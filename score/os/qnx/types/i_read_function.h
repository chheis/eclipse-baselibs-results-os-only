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
///
/// @file
/// @copyright Copyright (C) 2022, Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
///
/// @brief The pure virtual interfaces definitions for the read handler interface to be configured
/// by the user.
///

#ifndef SCORE_LIB_OS_QNX_RESOURCE_READ_HANDLER_INTERFACE_H
#define SCORE_LIB_OS_QNX_RESOURCE_READ_HANDLER_INTERFACE_H

// clang-format off
// the order is important to correctly define RESMGR_HANDLE_T, see QNX resmgr_attach() documentation
#include "score/os/qnx/types/iofunc_types.h"
// clang-format on

namespace score
{
namespace os
{

/// @brief Abstraction class to provide configurability for read() handler.
///
/// This interface implemented with QNX signature. shall be overriden  by the application that is
/// running the resource manager with the right functionality
class IReadFunction
{
  public:
    virtual ~IReadFunction() = default;
    // Below special member functions declared to avoid autosar_cpp14_a12_0_1_violation
    IReadFunction(const IReadFunction&) = default;
    IReadFunction& operator=(const IReadFunction&) = delete;
    IReadFunction(IReadFunction&& other) = delete;
    IReadFunction& operator=(IReadFunction&& other) = delete;
    virtual int operator()(resmgr_context_t* ctp, io_read_t* msg, RESMGR_OCB_T* ocb) = 0;

  protected:
    IReadFunction() = default;
};

}  // namespace os
}  // namespace score

#endif  // SCORE_LIB_OS_QNX_RESOURCE_READ_HANDLER_INTERFACE_H
