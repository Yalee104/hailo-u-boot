/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019-2024 Hailo Technologies Ltd. All rights reserved.
 *
 * Configuration for Hailo10.
 */

#ifndef __HAILO10_M2_H
#define __HAILO10_M2_H

#define SWUPDATE_MMC_INDEX "1"

#define BOOTMENU \
    /* Try all boot options by order */ \
    "bootmenu_0=Autodetect=" \
        "if test \"${auto_uboot_update_enable}\" = \"yes\"; then run auto_uboot_update; exit 1; fi; " \
        "echo Trying Boot from SD; run boot_mmc1;" \
        "echo Trying Boot from NFS; run bootnfs;" \
        "echo ERROR: All boot options failed\0" \
    "bootmenu_1=Boot from SD Card=run boot_mmc1\0" \
    "bootmenu_2=Update SD (wic) from TFTP=run update_wic_mmc1 && bootmenu -1\0" \
    "bootmenu_3=Update SD (partitions) from TFTP=run update_partitions_mmc1 && bootmenu -1\0" \
    "bootmenu_4=Boot from NFS=run bootnfs\0" \
    "default_spl_boot_source=mmc2\0" \
    "spl_boot_source=mmc2\0"

#define SWUPDATE_BOOTMENU_OPTION "bootmenu_5=SWUpdate=run boot_swupdate_mmc\0" \
                                 "bootmenu_6=SWUpdate AB board init=run boot_swupdate_ab_tftp\0"

#include "hailo15_common.h"

/*! @note: lpddr4 inline ecc located at the top 1/8 of the referred CS.
 *         In regards of using LPDDR4 setup of:
 *           - 2 ranks (Also refered as CS)
 *           - 2 channels per rank
 *           - Each channel is 16 bits wide => each rank is 32 bits bide
 *           - Rank size: 4G bytes
 *         If __not__ using ECC, then memory access are located in a single region:
 *           - 0x80000000 -  0x27fffffff: Bank #0 (8G = 0x200000000)
 *         If using ECC, then memory region is spilted to 2 ranges:
 *           - 0x080000000 - 0x15FFFFFFF: Bank #0     (3.5G = 0xE0000000)
 *           - 0x160000000 - 0x17fffffff: Bank #0 ECC (0.5G = 0x20000000)
 *           - 0x180000000 - 0x25fffffff: Bank #1     (3.5G = 0x70000000)
 *           - 0x260000000 - 0x27fffffff: Bank #1 ECC (0.5G = 0xE0000000)
 */

#endif /* __HAILO10_M2_H */