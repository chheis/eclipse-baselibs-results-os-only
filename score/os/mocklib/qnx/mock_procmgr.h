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
#ifndef SCORE_LIB_OS_MOCKLIB_QNX_MOCK_PROCMGR_H
#define SCORE_LIB_OS_MOCKLIB_QNX_MOCK_PROCMGR_H

#include "score/os/qnx/procmgr.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace score
{
namespace os
{

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Shadowing function name is intended. */

class MockProcMgr : public ProcMgr
{
  public:
    MOCK_METHOD((score::cpp::expected_blank<score::os::Error>),
                procmgr_ability,
                (pid_t pid, std::uint32_t ability),
                (const, noexcept, override));
    MOCK_METHOD((score::cpp::expected_blank<score::os::Error>),
                procmgr_ability,
                (const pid_t pid,
                 const std::uint32_t ability,
                 const std::uint32_t subrange_ability,
                 const std::uint64_t subrange_min,
                 const std::uint64_t subrange_max,
                 const std::uint32_t eol),
                (const, noexcept, override));
    MOCK_METHOD((score::cpp::expected_blank<score::os::Error>),
                procmgr_daemon,
                (const std::int32_t status, const std::uint32_t flags),
                (const, noexcept, override));
};

/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Shadowing function name is intended. */

}  // namespace os
}  // namespace score

#endif  // SCORE_LIB_OS_MOCKLIB_QNX_MOCK_PROCMGR_H
