/* arch/arm/mach-msm/include/mach/board-ext-htc.h
 *
 * HTC board.h extensions
 *
 * Copyright (C) 2013 CyanogenMod
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

#ifndef __ASM_ARCH_MSM_BOARD_EXT_HTC_H
#define __ASM_ARCH_MSM_BOARD_EXT_HTC_H

#define SHIP_BUILD	0
#define MFG_BUILD	1
#define ENG_BUILD	2

int board_mfg_mode(void);

int board_build_flag(void);

extern struct flash_platform_data msm_nand_data;

extern int emmc_partition_read_proc(char *page, char **start, off_t off,
		int count, int *eof, void *data);

extern int dying_processors_read_proc(char *page, char **start, off_t off,
		int count, int *eof, void *data);

#ifdef CONFIG_MSM_CAMERA
enum msm_camera_csi_data_format {
	CSI_8BIT,
	CSI_10BIT,
	CSI_12BIT,
};

struct msm_camera_csi_params {
	enum msm_camera_csi_data_format data_format;
	uint8_t lane_cnt;
	uint8_t lane_assign;
	uint8_t settle_cnt;
	uint8_t dpcm_scheme;
};

struct camera_led_info {
	uint16_t enable;
	uint16_t low_limit_led_state;
	uint16_t max_led_current_ma;
	uint16_t num_led_est_table;
};

struct camera_led_est {
	uint16_t enable;
	uint16_t led_state;
	uint16_t current_ma;
	uint16_t lumen_value;
	uint16_t min_step;
	uint16_t max_step;
};

struct camera_flash_info {
	struct camera_led_info *led_info;
	struct camera_led_est *led_est_table;
};

struct camera_flash_cfg {
	int num_flash_levels;
	int (*camera_flash)(int level);
	uint16_t low_temp_limit;
	uint16_t low_cap_limit;
	uint8_t postpone_led_mode;
	struct camera_flash_info *flash_info;
};

struct msm_camera_rawchip_info {
	int rawchip_reset;
	int rawchip_intr0;
	int rawchip_intr1;
	uint8_t rawchip_spi_freq;
	uint8_t rawchip_mclk_freq;
	int (*camera_rawchip_power_on)(void);
	int (*camera_rawchip_power_off)(void);
	int (*rawchip_use_ext_1v2)(void);
};

enum rawchip_enable_type {
	RAWCHIP_DISABLE,
	RAWCHIP_ENABLE,
	RAWCHIP_DXO_BYPASS,
	RAWCHIP_MIPI_BYPASS,
};

enum camera_vreg_type {
	REG_LDO,
	REG_VS,
	REG_GPIO,
};

enum sensor_flip_mirror_info {
	CAMERA_SENSOR_NONE,
	CAMERA_SENSOR_MIRROR,
	CAMERA_SENSOR_FLIP,
	CAMERA_SENSOR_MIRROR_FLIP,
};

struct camera_vreg_t {
	char *reg_name;
	enum camera_vreg_type type;
	int min_voltage;
	int max_voltage;
	int op_mode;
};
#endif /* CONFIG_MSM_CAMERA */

#endif /* __ASM_ARCH_MSM_BOARD_EXT_HTC_H */

