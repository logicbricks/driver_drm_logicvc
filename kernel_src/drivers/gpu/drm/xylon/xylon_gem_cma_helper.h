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

#ifndef __XYLON_DRM_GEM_CMA_HELPER_H__
#define __XYLON_DRM_GEM_CMA_HELPER_H__

#include <uapi/linux/types.h>
#include <drm/drmP.h>

/*
Internal fuctions from "drm_gem_cma_helper.c"*/

int drm_gem_cma_dumb_map_offset(struct drm_file *file_priv,
				struct drm_device *drm, u32 handle,
				u64 *offset);

#endif /* __XYLON_DRM_GEM_CMA_HELPER_H__ */
