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
#include "dirent_impl.h"

namespace score
{
namespace os
{

/* KW_SUPPRESS_START:AUTOSAR.MEMB.VIRTUAL.FINAL: Compiler warn suggests override */
/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected<DIR*, score::os::Error> DirentImpl::opendir(const char* const name) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
/* KW_SUPPRESS_END:AUTOSAR.MEMB.VIRTUAL.FINAL: Compiler warn suggests override */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    DIR* const dir_ptr = ::opendir(name);
    if (dir_ptr == nullptr)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return dir_ptr;
}
/* KW_SUPPRESS_START:AUTOSAR.MEMB.VIRTUAL.FINAL: Compiler warn suggests override */
/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected<struct dirent*, score::os::Error> DirentImpl::readdir(DIR* const dirp) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
/* KW_SUPPRESS_END:AUTOSAR.MEMB.VIRTUAL.FINAL: Compiler warn suggests override */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    struct dirent* const dirent_ptr = ::readdir(dirp);
    if (dirent_ptr == nullptr)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return dirent_ptr;
}
/* KW_SUPPRESS_START:AUTOSAR.MEMB.VIRTUAL.FINAL: Compiler warn suggests override */
/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
// Rationale: violation is happening out of our code domain due to QNX - ::scandir, no harm to our code
// coverity[autosar_cpp14_a5_0_3_violation] see above
score::cpp::expected<std::int32_t, score::os::Error> DirentImpl::scandir(
    /* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
    /* KW_SUPPRESS_END:AUTOSAR.MEMB.VIRTUAL.FINAL: Compiler warn suggests override */
    const char* const dirp,
    /* KW_SUPPRESS_START:MISRA.PTR.TO_PTR_TO_PTR:Used parameters match the param requirements of wrapped function */
    struct dirent*** const namelist,
    /* KW_SUPPRESS_END:MISRA.PTR.TO_PTR_TO_PTR:Used parameters match the param requirements of wrapped function */
    std::int32_t (*const filter)(const struct dirent*),
    std::int32_t (*const compar)(const struct dirent**, const struct dirent**)) const noexcept
{
    const std::int32_t number_of_entries = ::scandir(dirp, namelist, filter, compar);
    if (number_of_entries == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return number_of_entries;
}
/* KW_SUPPRESS_START:AUTOSAR.MEMB.VIRTUAL.FINAL: Compiler warn suggests override */
/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected_blank<score::os::Error> DirentImpl::closedir(DIR* const dirp) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
/* KW_SUPPRESS_END:AUTOSAR.MEMB.VIRTUAL.FINAL: Compiler warn suggests override */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    if (::closedir(dirp) == -1) /* LCOV_EXCL_BR_LINE: Not possible to make closedir return -1 through unit test. */
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno()); /* LCOV_EXCL_LINE */
        /* ::closedir() only fails if a signal interrupted the call.  Which can not be easily simulated in a unit test.
            On failure, ::pclose will return -1 and set errno */
    }
    return {};
}

}  // namespace os
}  // namespace score
