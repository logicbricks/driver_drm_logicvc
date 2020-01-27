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

#include <linux/export.h>
#include <drm/drmP.h>

#include "xylon_platform.h"

/*
 * Register.
 *
 * \param platdev - Platform device struture
 * \return zero on success or a negative number on failure.
 *
 * Attempt to gets inter module "drm" information. If we are first
 * then register the character device and inter module information.
 * Try and register, if we fail to register, backout previous work.
 */

static int drm_get_platform_dev(struct platform_device *platdev,
				struct drm_driver *driver)
{
	struct drm_device *dev;
	int ret;

	DRM_DEBUG("\n");

	dev = drm_dev_alloc(driver, &platdev->dev);
	if (IS_ERR(dev))
		return PTR_ERR(dev);

	dev->platformdev = platdev;

	ret = drm_dev_register(dev, 0);
	if (ret)
		goto err_free;

	DRM_INFO("Initialized %s %d.%d.%d %s on minor %d\n",
		 driver->name, driver->major, driver->minor, driver->patchlevel,
		 driver->date, dev->primary->index);

	return 0;

err_free:
	drm_dev_unref(dev);
	return ret;
}

/**
 * drm_platform_init - Register a platform device with the DRM subsystem
 * @driver: DRM device driver
 * @platform_device: platform device to register
 *
 * Registers the specified DRM device driver and platform device with the DRM
 * subsystem, initializing a drm_device structure and calling the driver's
 * .load() function.
 *
 * NOTE: This function is deprecated, please use drm_dev_alloc() and
 * drm_dev_register() instead and remove your ->load() callback.
 *
 * Return: 0 on success or a negative error code on failure.
 */
int drm_platform_init(struct drm_driver *driver, struct platform_device *platform_device)
{
	DRM_DEBUG("\n");

	return drm_get_platform_dev(platform_device, driver);
}
//EXPORT_SYMBOL(drm_platform_init);
