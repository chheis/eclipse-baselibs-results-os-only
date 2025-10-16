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
#include "score/os/linux/getmntent.h"

namespace score
{
namespace os
{

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function */
struct mntent* getMntent(FILE* const stream)
{
    return ::getmntent(stream);
}
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function */

} /* namespace os */
} /* namespace score */
