/*
 * Xylon DRM driver functions
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

#include <linux/kernel.h>

#include <drm/drm_gem_cma_helper.h>

#include "xylon_gem_cma_helper.h"

/**
 * drm_gem_cma_dumb_map_offset - return the fake mmap offset for a CMA GEM
 *     object
 * @file_priv: DRM file-private structure containing the GEM object
 * @drm: DRM device
 * @handle: GEM object handle
 * @offset: return location for the fake mmap offset
 *
 * This function look up an object by its handle and returns the fake mmap
 * offset associated with it. Drivers using the CMA helpers should set this
 * as their DRM driver's ->dumb_map_offset() callback.
 *
 * Returns:
 * 0 on success or a negative error code on failure.
 */
int drm_gem_cma_dumb_map_offset(struct drm_file *file_priv,
				struct drm_device *drm, u32 handle,
				u64 *offset)
{
	struct drm_gem_object *gem_obj;

	gem_obj = drm_gem_object_lookup(file_priv, handle);
	if (!gem_obj) {
		dev_err(drm->dev, "failed to lookup GEM object\n");
		return -EINVAL;
	}

	*offset = drm_vma_node_offset_addr(&gem_obj->vma_node);

	drm_gem_object_unreference_unlocked(gem_obj);

	return 0;
}
