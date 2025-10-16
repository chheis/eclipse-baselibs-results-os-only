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
#ifndef SCORE_LIB_OS_UTILS_INTERPROCESSCONDITIONALVARIABLE_H
#define SCORE_LIB_OS_UTILS_INTERPROCESSCONDITIONALVARIABLE_H

#include "score/os/utils/interprocess/interprocess_mutex.h"

#include <sys/types.h>
#include <mutex>

namespace score
{
namespace os
{

class InterprocessConditionalVariable
{
  public:
    InterprocessConditionalVariable() noexcept;
    ~InterprocessConditionalVariable() noexcept;
    InterprocessConditionalVariable(const InterprocessConditionalVariable&) = delete;
    InterprocessConditionalVariable(InterprocessConditionalVariable&&) noexcept = delete;
    InterprocessConditionalVariable& operator=(const InterprocessConditionalVariable&) = delete;
    InterprocessConditionalVariable& operator=(InterprocessConditionalVariable&&) noexcept = delete;

    void notify_one() noexcept;
    void notify_all() noexcept;
    /* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
    void wait(std::unique_lock<InterprocessMutex>& lock) noexcept;
    /* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */

    template <class Predicate>
    void wait(std::unique_lock<InterprocessMutex>& lock, Predicate pred)
    {
        while (pred() == false)
        {
            this->wait(lock);
        }
    }

  private:
    pthread_cond_t conditionalVariable{};
};
}  // namespace os
}  // namespace score

#endif  // SCORE_LIB_OS_UTILS_INTERPROCESSCONDITIONALVARIABLE_H
