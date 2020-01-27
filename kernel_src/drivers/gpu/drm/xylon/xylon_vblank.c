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

#include "xylon_vblank.h"

void xylon_drm_vblank_cleanup(struct drm_device *dev)
{
	unsigned int pipe;

	/* Bail if the driver didn't call drm_vblank_init() */
	if (dev->num_crtcs == 0)
		return;

	for (pipe = 0; pipe < dev->num_crtcs; pipe++) {
		struct drm_vblank_crtc *vblank = &dev->vblank[pipe];

		WARN_ON(READ_ONCE(vblank->enabled) &&
			drm_core_check_feature(dev, DRIVER_MODESET));

		del_timer_sync(&vblank->disable_timer);
	}

	kfree(dev->vblank);

	dev->num_crtcs = 0;
}

u32 xylon_drm_vblank_count(struct drm_device *dev, unsigned int pipe)
{
	struct drm_vblank_crtc *vblank = &dev->vblank[pipe];

	if (WARN_ON(pipe >= dev->num_crtcs))
		return 0;

	return vblank->count;
}
