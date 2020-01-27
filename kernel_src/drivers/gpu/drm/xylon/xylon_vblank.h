/*
 * Xylon DRM driver header
 *
 * Copyright (C) 2018 Xylon d.o.o.
 * Author: Josip Vladic <josip.vladic@logicbricks.com>
 *
 * Based on Xilinx DRM header.
 * Copyright (C) 2018 Xilinx, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __XYLON_DRM_VBLANK_H__
#define __XYLON_DRM_VBLANK_H__

#include <drm/drmP.h>

/*
Internal fuctions from "drm_vblank.c"*/

void xylon_drm_vblank_cleanup(struct drm_device *dev);
u32 xylon_drm_vblank_count(struct drm_device *dev, unsigned int pipe);

#endif /* __XYLON_DRM_VBLANK_H__ */
