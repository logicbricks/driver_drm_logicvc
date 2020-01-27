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

#ifndef __XYLON_DRM_PLATFORM_H__
#define __XYLON_DRM_PLATFORM_H__

/*
Internal fuctions from "drm_platform.c"*/

int drm_platform_init(struct drm_driver *driver, struct platform_device *platform_device);

#endif /* __XYLON_DRM_PLATFORM_H__ */
