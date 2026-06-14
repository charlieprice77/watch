/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>
#include <zephyr/drivers/display.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

#define COLOR_RED   0xF800
#define COLOR_GREEN 0x07E0
#define COLOR_BLUE  0x001F
#define COLOR_WHITE 0xFFFF

// /* --- BMI270 --- */
//
// int configure_bmi270(const struct device *const dev)
// {
// 	struct sensor_value full_scale, sampling_freq, oversampling;
//
// 	if (!device_is_ready(dev)) {
// 		LOG_ERR("BMI270 not ready");
// 		return -ENODEV;
// 	}
//
// 	LOG_INF("BMI270 found: %s", dev->name);
//
// 	full_scale.val1 = 2;
// 	full_scale.val2 = 0;
// 	sampling_freq.val1 = 100;
// 	sampling_freq.val2 = 0;
// 	oversampling.val1 = 1;
// 	oversampling.val2 = 0;
//
// 	sensor_attr_set(dev, SENSOR_CHAN_ACCEL_XYZ, SENSOR_ATTR_FULL_SCALE, &full_scale);
// 	sensor_attr_set(dev, SENSOR_CHAN_ACCEL_XYZ, SENSOR_ATTR_OVERSAMPLING, &oversampling);
// 	sensor_attr_set(dev, SENSOR_CHAN_ACCEL_XYZ, SENSOR_ATTR_SAMPLING_FREQUENCY, &sampling_freq);
//
// 	full_scale.val1 = 500;
// 	full_scale.val2 = 0;
// 	sampling_freq.val1 = 100;
// 	sampling_freq.val2 = 0;
// 	oversampling.val1 = 1;
// 	oversampling.val2 = 0;
//
// 	sensor_attr_set(dev, SENSOR_CHAN_GYRO_XYZ, SENSOR_ATTR_FULL_SCALE, &full_scale);
// 	sensor_attr_set(dev, SENSOR_CHAN_GYRO_XYZ, SENSOR_ATTR_OVERSAMPLING, &oversampling);
// 	sensor_attr_set(dev, SENSOR_CHAN_GYRO_XYZ, SENSOR_ATTR_SAMPLING_FREQUENCY, &sampling_freq);
//
// 	return 0;
// }
//
// void sample_bmi270(const struct device *const dev, struct sensor_value acc[3],
// 		   struct sensor_value gyr[3])
// {
// 	sensor_sample_fetch(dev);
// 	sensor_channel_get(dev, SENSOR_CHAN_ACCEL_XYZ, acc);
// 	sensor_channel_get(dev, SENSOR_CHAN_GYRO_XYZ, gyr);
//
// 	LOG_INF("AX: %d.%06d AY: %d.%06d AZ: %d.%06d "
// 		"GX: %d.%06d GY: %d.%06d GZ: %d.%06d",
// 		acc[0].val1, acc[0].val2, acc[1].val1, acc[1].val2,
// 		acc[2].val1, acc[2].val2, gyr[0].val1, gyr[0].val2,
// 		gyr[1].val1, gyr[1].val2, gyr[2].val1, gyr[2].val2);
// }

/* --- Main --- */

int main(void)
{
	// const struct device *const bmi270_dev = DEVICE_DT_GET_ONE(bosch_bmi270);
	const struct device *const display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));

	// configure_bmi270(bmi270_dev);
	display_test(display_dev);

	// struct sensor_value acc[3], gyr[3];

	while (1) {
		k_sleep(K_MSEC(10));
		// sample_bmi270(bmi270_dev, acc, gyr);
	}

	return 0;
}
