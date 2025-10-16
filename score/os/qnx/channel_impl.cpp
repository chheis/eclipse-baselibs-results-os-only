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
#include "score/os/qnx/channel_impl.h"

namespace score
{
namespace os
{

static_assert(sizeof(std::size_t) == sizeof(_Sizet), "unexpected _Sizet");

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
/* KW_SUPPRESS_START:MISRA.USE.EXPANSION:Using library-defined macro to ensure correct operation */
score::cpp::expected<std::int32_t, score::os::Error> ChannelImpl::MsgReceive(const std::int32_t chid,
                                                                    void* const msg,
                                                                    const std::size_t bytes,
                                                                    _msg_info* const info) const noexcept
/* KW_SUPPRESS_END:MISRA.USE.EXPANSION:Using library-defined macro to ensure correct operation */
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    const std::int32_t result = ::MsgReceive(chid, msg, bytes, info);
    if (result == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return result;
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
/* KW_SUPPRESS_START:MISRA.USE.EXPANSION:Using library-defined macro to ensure correct operation */
score::cpp::expected<std::int32_t, score::os::Error> ChannelImpl::MsgReceivev(const std::int32_t chid,
                                                                     const iov_t* const riov,
                                                                     const std::size_t rparts,
                                                                     struct _msg_info* const info) const noexcept
/* KW_SUPPRESS_END:MISRA.USE.EXPANSION:Using library-defined macro to ensure correct operation */
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    const std::int32_t result = ::MsgReceivev(chid, riov, rparts, info);
    if (result == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return result;
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
/* KW_SUPPRESS_START:MISRA.USE.EXPANSION:Using library-defined macro to ensure correct operation */
score::cpp::expected<std::int32_t, score::os::Error> ChannelImpl::MsgReceivePulse(const std::int32_t chid,
                                                                         void* const pulse,
                                                                         const std::size_t bytes,
                                                                         _msg_info* const info) const noexcept
/* KW_SUPPRESS_END:MISRA.USE.EXPANSION:Using library-defined macro to ensure correct operation */
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    const std::int32_t result = ::MsgReceivePulse(chid, pulse, bytes, info);
    if (result == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return result;
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected_blank<score::os::Error> ChannelImpl::MsgReply(const std::int32_t rcvid,
                                                          const std::int64_t status,
                                                          const void* const msg,
                                                          const std::size_t bytes) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    if (::MsgReply(rcvid, status, msg, bytes) == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return {};
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected_blank<score::os::Error> ChannelImpl::MsgReplyv(const std::int32_t rcvid,
                                                           const std::int64_t status,
                                                           const iov_t* const riov,
                                                           const std::size_t rparts) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    if (::MsgReplyv(rcvid, status, riov, rparts) == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return {};
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected_blank<score::os::Error> ChannelImpl::MsgError(const std::int32_t rcvid,
                                                          const std::int32_t err) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    if (::MsgError(rcvid, err) == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return {};
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected<std::int64_t, score::os::Error> ChannelImpl::MsgSend(const std::int32_t coid,
                                                                 const void* const smsg,
                                                                 const std::size_t sbytes,
                                                                 void* const rmsg,
                                                                 const std::size_t rbytes) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    const std::int64_t result = ::MsgSend(coid, smsg, sbytes, rmsg, rbytes);
    if (result == -1L)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return result;
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected<std::int64_t, score::os::Error> ChannelImpl::MsgSendv(const std::int32_t coid,
                                                                  const iov_t* const siov,
                                                                  const std::size_t sparts,
                                                                  iov_t* const riov,
                                                                  const std::size_t rparts) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    const std::int64_t result = ::MsgSendv(coid, siov, sparts, riov, rparts);
    if (result == -1L)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return result;
}

// this is a wrapper only, pointers will be used below anyway
// coverity[autosar_cpp14_a8_4_10_violation]
void ChannelImpl::SetIov(iov_t* const msg, void* const addr, const size_t len) const noexcept
{
    /* KW_SUPPRESS_START:MISRA.USE.EXPANSION:Using library-defined macro to ensure correct operation */
    // Cast is happening outside our code domain
    // coverity[autosar_cpp14_a5_2_2_violation]
#if defined(__clang__)
#pragma clang diagnostic push
// FIXME: @codeowners please add justification here (cf. platform/aas/intc/typedmemd/code/io_handler/typedmemoryio.cpp)
#pragma clang diagnostic warning "-Wc99-extensions"
#endif
    SETIOV(msg, addr, len);
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    /* KW_SUPPRESS_END:MISRA.USE.EXPANSION:Using library-defined macro to ensure correct operation */
}

// this is a wrapper only, pointers will be used below anyway
// coverity[autosar_cpp14_a8_4_10_violation]
void ChannelImpl::SetIovConst(iov_t* const msg, const void* const addr, const size_t len) const noexcept
{
/* KW_SUPPRESS_START:MISRA.USE.EXPANSION:Using library-defined macro to ensure correct operation */
#if defined(__clang__)
#pragma clang diagnostic push
// FIXME: @codeowners please add justification here (cf. platform/aas/intc/typedmemd/code/io_handler/typedmemoryio.cpp)
#pragma clang diagnostic warning "-Wc99-extensions"
#endif
    SETIOV_CONST(msg, addr, len);
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
    /* KW_SUPPRESS_END:MISRA.USE.EXPANSION:Using library-defined macro to ensure correct operation */
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected_blank<score::os::Error> ChannelImpl::MsgSendPulse(const std::int32_t coid,
                                                              const std::int32_t priority,
                                                              const std::int32_t code,
                                                              const std::int32_t value) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    if (::MsgSendPulse(coid, priority, code, value) == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return {};
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected_blank<score::os::Error> ChannelImpl::MsgSendPulsePtr(const std::int32_t coid,
                                                                 const std::int32_t priority,
                                                                 const std::int32_t code,
                                                                 void* const value) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    if (::MsgSendPulsePtr(coid, priority, code, value) == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return {};
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected_blank<score::os::Error> ChannelImpl::MsgDeliverEvent(const std::int32_t rcvid,
                                                                 const struct sigevent* const event) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    if (::MsgDeliverEvent(rcvid, event) == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return {};
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected_blank<score::os::Error> ChannelImpl::ConnectClientInfo(const std::int32_t scoid,
                                                                   _client_info* const info,
                                                                   const std::int32_t ngroups) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    if (::ConnectClientInfo(scoid, info, ngroups) == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return {};
}
/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected<std::int32_t, score::os::Error> ChannelImpl::ConnectAttach(const std::uint32_t reserved,
                                                                       const pid_t pid,
                                                                       const std::int32_t chid,
                                                                       const std::uint32_t index,
                                                                       const std::int32_t flags) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    // Suppressed here because usage of this OSAL method is on banned list
    // NOLINTNEXTLINE(score-banned-function) see comment above
    const std::int32_t result = ::ConnectAttach(reserved, pid, chid, index, flags);
    if (result == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return result;
}

/* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
score::cpp::expected_blank<score::os::Error> ChannelImpl::ConnectDetach(const std::int32_t coid) const noexcept
/* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
{
    if (::ConnectDetach(coid) == -1)
    {
        return score::cpp::make_unexpected(score::os::Error::createFromErrno());
    }
    return {};
}

}  // namespace os
}  // namespace score
