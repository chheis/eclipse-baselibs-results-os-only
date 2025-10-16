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
#ifndef SCORE_LIB_OS_GETOPT_IMPL_H
#define SCORE_LIB_OS_GETOPT_IMPL_H

#include "score/os/getopt.h"

namespace score
{
namespace os
{
class GetoptImpl final : public Getopt
{
  public:
    constexpr GetoptImpl() = default;

  private:
    /* KW_SUPPRESS_START:AUTOSAR.BUILTIN_NUMERIC:Char is used in respect to the wrapped function's signature */
    /* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:The wrapper function is identifiable through namespace */
    /* KW_SUPPRESS_START:AUTOSAR.ARRAY.CSTYLE:Wrapped function's signature requires C-style array */
    std::int32_t getopt(const std::int32_t argc,
                        char* const argv[],  // NOLINT(modernize-avoid-c-arrays) see comment above
                        const char* const optstring) const noexcept override;
    /* KW_SUPPRESS_END:AUTOSAR.ARRAY.CSTYLE:Wrapped function's signature requires C-style array */
    /* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:The wrapper function is identifiable through namespace */
    /* KW_SUPPRESS_END:AUTOSAR.BUILTIN_NUMERIC:Char is used in respect to the wrapped function's signature */
    std::int32_t getoptopt() const noexcept override;
    std::int32_t getoptind() const noexcept override;
    std::int32_t getopterr() const noexcept override;
    /* KW_SUPPRESS_START:AUTOSAR.BUILTIN_NUMERIC:Char is used in respect to the wrapped function's signature */
    /* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:The wrapper function is identifiable through namespace */
    /* KW_SUPPRESS_START:AUTOSAR.ARRAY.CSTYLE:Wrapped function's signature requires C-style array */
    // Wrapped function's signature requires C-style array
    std::int32_t getopt_long(const std::int32_t argc,
                             char* const argv[],  // NOLINT(modernize-avoid-c-arrays) see comment above
                             const char* const optstring,
                             const option* const option,
                             std::int32_t* const index) const noexcept override;
    /* KW_SUPPRESS_END:AUTOSAR.ARRAY.CSTYLE:Wrapped function's signature requires C-style array */
    /* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:The wrapper function is identifiable through namespace */
    /* KW_SUPPRESS_END:AUTOSAR.BUILTIN_NUMERIC:Char is used in respect to the wrapped function's signature */
};
}  // namespace os
}  // namespace score

#endif  // SCORE_LIB_OS_GETOPT_IMPL_H
