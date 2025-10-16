/********************************************************************************
 * Copyright (c) 2025 Contributors to the Eclipse Foundation
 *
 * See the NOTICE file(s) distributed with this work for additional
 * information regarding copyright ownership.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0
 *
 * SPDX-License-Identifier: Apache-2.0
 ********************************************************************************/
#ifndef SCORE_LIB_OS_STATIC_DESTRUCTION_GUARD_H
#define SCORE_LIB_OS_STATIC_DESTRUCTION_GUARD_H

#include <cstdint>
#include <type_traits>

namespace score
{
namespace os
{

/// \brief An abstraction of the Nifty Counter Idiom which ensures that variables with static storage duration are only
/// destructed after _all_ their users are destructed. This shall only be used if a static variable is used in a
/// destructor.
///
/// \tparam T Any type with static storage duration that shall be protected
///
/// \details Be aware that this idiom will create overhead on loading the binary. Correctly applied each translation
/// unit will create an instance of a typed version of this class. Will cause that for each translation unit respective
/// underlying constructor is called. Thus you really want to try to avoid spreading the usage as much as possible.
///
/// The C++ Standard forbids concurrent static construction or destruction. Thus, no thread-safety measurements need to
/// be applied.
template <typename T>
class StaticDestructionGuard
{
  public:
    using StorageType = std::aligned_storage_t<sizeof(T), alignof(T)>;

    /// \brief Enables access to underlying local storage
    /// \return StorageType&, be aware that the storage is only filled correctly once the constructor was invoked.
    static StorageType& GetStorage()
    {
        static StorageType storage;
        return storage;
    }

    /// \brief Constructs T in local storage upon first usage
    constexpr StaticDestructionGuard()
    {
        auto& counter_value = GetCounter();
        const auto previous_counter_value = counter_value;
        // LCOV_EXCL_START
        // LCOV false positive: defensive programming, unreachable branching for Int32max objects creation
        if (previous_counter_value < INT32_MAX)
        {
            // LCOV_EXCL_STOP
            // coverity[autosar_cpp14_a7_4_1_violation] Already handled upper limit silently, no throw
            counter_value++;
            if (previous_counter_value == 0)
            {
                // NOLINTBEGIN(score-no-dynamic-raw-memory): safe usage of new
                // Suppress "AUTOSAR C++14 A18-5-10" rule finding: "Placement new shall be used only with properly
                // aligned pointers to sufficient storage capacity." Rationale: 'new' ensures proper object construction
                // by dynamically allocating memory within GetStorage(). This allows us to manage initialization,
                // required for handlingr static storage. Although this approach goes against AUTOSAR rule A18-5-10, it
                // is essential to ensure proper object construction.
                // coverity[autosar_cpp14_a18_5_10_violation]
                new (&GetStorage()) T();
                // NOLINTEND(score-no-dynamic-raw-memory): safe usage of new
            }
        }
    };

    /// \brief Destructs T in local storage upon last usage
    ~StaticDestructionGuard()
    {
        auto& counter_value = GetCounter();
        // LCOV_EXCL_START
        // LCOV false positive: defensive programming, unreachable branching
        if (counter_value > 0)
        {
            // LCOV_EXCL_STOP
            // coverity[autosar_cpp14_a7_4_1_violation] Already handled lower limit silently, no throw
            --counter_value;
            if (counter_value == 0)
            {
                // NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast): safe usage of reintrpret_cast
                // Suppress “AUTOSAR_Cpp14_A5_2_4” rule finding: “Reinterpret_cast shall not be used.”
                // Rationale: Reinterpret_cast is used to safely treat StorageType as type T, allowing proper
                // destruction. This usage is considered safe in this context, despite AUTOSAR A5-2-4 prohibition.
                // coverity[autosar_cpp14_a5_2_4_violation]
                reinterpret_cast<T&>(GetStorage()).~T();
                // NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast): safe usage of reintrpret_cast
            }
        }
    };

    StaticDestructionGuard(const StaticDestructionGuard&) = default;
    StaticDestructionGuard& operator=(const StaticDestructionGuard&) = default;
    StaticDestructionGuard(StaticDestructionGuard&&) noexcept = default;
    StaticDestructionGuard& operator=(StaticDestructionGuard&&) noexcept = default;

  private:
    static std::int32_t& GetCounter()
    {
        static std::int32_t counter;
        return counter;
    }
};

}  // namespace os
}  // namespace score

#endif  // SCORE_LIB_OS_STATIC_DESTRUCTION_GUARD_H
