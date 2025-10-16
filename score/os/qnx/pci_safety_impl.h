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
#ifndef SCORE_LIB_OS_QNX_PCI_SAFETY_IMPL_H
#define SCORE_LIB_OS_QNX_PCI_SAFETY_IMPL_H

#include "score/os/qnx/pci_safety.h"

namespace score
{
namespace os
{
namespace qnx
{

class PciSafetyImpl final : public PciSafety
{
  public:
    pci_bdf_t pci_bdf(const std::uint8_t bus, const std::uint8_t dev, const std::uint8_t func) const noexcept override;

    /* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
    score::cpp::expected_blank<std::string> pci_device_cfg_rd32(const pci_bdf_t bdf,
                                                         const std::uint16_t offset,
                                                         std::uint32_t* const val) const noexcept override;
    /* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */

    /* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
    score::cpp::expected_blank<std::string> pci_device_read_did(const pci_bdf_t bdf,
                                                         pci_did_t* const did) const noexcept override;
    /* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */

    /* KW_SUPPRESS_START:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */
    score::cpp::expected_blank<std::string> pci_device_read_vid(const pci_bdf_t bdf,
                                                         pci_vid_t* const vid) const noexcept override;
    /* KW_SUPPRESS_END:MISRA.VAR.HIDDEN:Wrapper function is identifiable through namespace usage */

  private:
    static const char* const kPciErrorMsg;
};

}  // namespace qnx
}  // namespace os
}  // namespace score

#endif  // SCORE_LIB_OS_QNX_PCI_SAFETY_IMPL_H
