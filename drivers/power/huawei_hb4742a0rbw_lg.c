
#include <linux/mfd/pm8xxx/batterydata-lib.h>

static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {2512, 2513, 2506, 2500, 2483},
	.cols		= 5
};

static struct single_row_lut fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols		= 1
};

static struct sf_lut rbatt_sf = {
	.rows		= 30,
	.cols			= 5,
	.row_entries	= {-20, 0, 25, 40, 60},
	.percent		= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
	.sf			= {
					{1669, 377, 100, 75, 65},
					{1666, 377, 100, 75, 65},
					{1604, 385, 106, 78, 66},
					{1560, 391, 112, 82, 69},
					{1548, 392, 118, 87, 72},
					{1540, 396, 126, 92, 76},
					{1557, 391, 135, 98, 78},
					{1588, 392, 143, 104, 82},
					{1622, 400, 135, 106, 86},
					{1663, 410, 111, 89, 77},
					{1716, 422, 108, 79, 67},
					{1783, 439, 113, 84, 70},
					{1862, 462, 120, 88, 75},
					{1955, 493, 128, 92, 79},
					{2131, 533, 134, 92, 77},
					{2418, 585, 139, 91, 71},
					{2729, 646, 139, 90, 70},
					{2948, 698, 137, 90, 70},
					{2607, 686, 133, 86, 69},
					{2895, 717, 143, 92, 73},
					{3081, 738, 149, 96, 74},
					{3296, 763, 157, 100, 76},
					{3554, 787, 164, 103, 77},
					{3866, 813, 169, 103, 74},
					{4251, 839, 166, 97, 73},
					{4740, 869, 162, 98, 76},
					{5397, 911, 170, 103, 82},
					{6354, 971, 187, 119, 98},
					{7849, 1064, 231, 149, 112},
					{12076, 2125, 337, 203, 138},
				   }
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 31,
	.cols			= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent		= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv			= {
					{4352, 4349, 4344, 4340, 4333},
					{4265, 4276, 4278, 4276, 4271},
					{4195, 4215, 4221, 4219, 4215},
					{4130, 4157, 4165, 4164, 4160},
					{4072, 4100, 4112, 4111, 4107},
					{4007, 4046, 4063, 4061, 4058},
					{3953, 3987, 4013, 4014, 4012},
					{3909, 3940, 3969, 3971, 3969},
					{3870, 3902, 3925, 3929, 3928},
					{3836, 3866, 3876, 3881, 3881},
					{3807, 3834, 3844, 3844, 3844},
					{3782, 3807, 3819, 3820, 3820},
					{3760, 3785, 3799, 3800, 3799},
					{3740, 3767, 3783, 3782, 3782},
					{3721, 3750, 3769, 3766, 3761},
					{3702, 3737, 3755, 3748, 3735},
					{3681, 3723, 3731, 3724, 3710},
					{3663, 3710, 3700, 3692, 3679},
					{3649, 3697, 3684, 3676, 3665},
					{3633, 3687, 3681, 3674, 3663},
					{3624, 3682, 3680, 3673, 3662},
					{3613, 3677, 3678, 3671, 3660},
					{3601, 3670, 3674, 3668, 3656},
					{3586, 3658, 3667, 3660, 3644},
					{3566, 3637, 3646, 3635, 3616},
					{3541, 3602, 3605, 3592, 3574},
					{3504, 3551, 3549, 3538, 3521},
					{3453, 3480, 3480, 3472, 3460},
					{3373, 3377, 3395, 3391, 3377},
					{3245, 3243, 3273, 3264, 3248},
					{3000, 3000, 3000, 3000, 3000}
				    }
};

struct bms_battery_data Huawei_HB4742A0RBW_LG_data= {
	.fcc					= 2420,
	.fcc_temp_lut			= &fcc_temp,
	.fcc_sf_lut			= &fcc_sf,
	.pc_temp_ocv_lut		= &pc_temp_ocv,
	.rbatt_sf_lut			= &rbatt_sf,
	.default_rbatt_mohm	= 127
};