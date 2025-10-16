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
#ifndef SCORE_LIB_OS_LINUX_TIMEX_H
#define SCORE_LIB_OS_LINUX_TIMEX_H

#include <time.h>
#include <cstdint>

namespace score
{
namespace os
{

std::int32_t clock_adjtime(const clockid_t clkid, struct timex* tx);

}  // namespace os
}  // namespace score

#endif  // SCORE_LIB_OS_LINUX_TIMEX_H
