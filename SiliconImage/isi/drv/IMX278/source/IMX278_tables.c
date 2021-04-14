/*****************************************************************************/
/*  This is an unpublished work, the copyright in which vests in Silicon Image
 *  GmbH. The information contained herein is the property of Silicon Image GmbH
 *  and is supplied without liability for errors or omissions. No part may be
 *  reproduced or used expect as authorized by contract or other written
 *  permission. Copyright(c) Silicon Image GmbH, 2009, all rights reserved.
 */
/*****************************************************************************/

#include <ebase/types.h>
#include <ebase/trace.h>
#include <ebase/builtins.h>

#include <common/return_codes.h>

#include "isi.h"
#include "isi_iss.h"
#include "isi_priv.h"
#include "IMX278_MIPI_priv.h"


/*****************************************************************************
 * DEFINES
 *****************************************************************************/


/*****************************************************************************
 * GLOBALS
 *****************************************************************************/

//four lane
const IsiRegDescription_t Sensor_g_aRegDescription_fourlane[] =
{
	{0x0100,	0x00, "0x0100", eReadWrite}, 

	{0x0136,	0x0C, "0x0100", eReadWrite},
	{0x0137,	0x00, "0x0100", eReadWrite},
	 
	{0x3042,	0x01, "0x0100", eReadWrite},
	{0x5CE8,	0x00, "0x0100", eReadWrite},
	{0x5CE9,	0x91, "0x0100", eReadWrite},
	{0x5CEA,	0x00, "0x0100", eReadWrite},
	{0x5CEB,	0x2A, "0x0100", eReadWrite},
	{0x5F1B,	0x01, "0x0100", eReadWrite},
	{0x5C2C,	0x01, "0x0100", eReadWrite},
	{0x5C2D,	0xFF, "0x0100", eReadWrite},
	{0x5C2E,	0x00, "0x0100", eReadWrite},
	{0x5C2F,	0x00, "0x0100", eReadWrite},
	{0x5F0D,	0x6E, "0x0100", eReadWrite},
	{0x5F0E,	0x7C, "0x0100", eReadWrite},
	{0x5F0F,	0x14, "0x0100", eReadWrite},
	{0x6100,	0x30, "0x0100", eReadWrite},
	{0x6101,	0x12, "0x0100", eReadWrite},
	{0x6102,	0x14, "0x0100", eReadWrite},
	{0x6104,	0x91, "0x0100", eReadWrite},
	{0x6105,	0x30, "0x0100", eReadWrite},
	{0x6106,	0x11, "0x0100", eReadWrite},
	{0x6107,	0x12, "0x0100", eReadWrite},
	{0x6505,	0xC4, "0x0100", eReadWrite},
	{0x6507,	0x25, "0x0100", eReadWrite},
	{0x6508,	0xE1, "0x0100", eReadWrite},
	{0x6509,	0xD7, "0x0100", eReadWrite},
	{0x650A,	0x20, "0x0100", eReadWrite},
	{0x7382,	0x01, "0x0100", eReadWrite},
	{0x7383,	0x13, "0x0100", eReadWrite},
	{0x7788,	0x04, "0x0100", eReadWrite},
	{0x9006,	0x0C, "0x0100", eReadWrite},
	{0xB000,	0x78, "0x0100", eReadWrite},
	{0xB001,	0xB6, "0x0100", eReadWrite},
	{0xB002,	0x78, "0x0100", eReadWrite},
	{0xB003,	0xB7, "0x0100", eReadWrite},
	{0xB004,	0x98, "0x0100", eReadWrite},
	{0xB005,	0x00, "0x0100", eReadWrite},
	{0xB006,	0x98, "0x0100", eReadWrite},
	{0xB007,	0x01, "0x0100", eReadWrite},
	{0xB008,	0x98, "0x0100", eReadWrite},
	{0xB009,	0x02, "0x0100", eReadWrite},
	{0xB00A,	0xA9, "0x0100", eReadWrite},
	{0xB00B,	0x0F, "0x0100", eReadWrite},
	{0xB00C,	0xA9, "0x0100", eReadWrite},
	{0xB00D,	0x12, "0x0100", eReadWrite},
	{0xB00E,	0xA9, "0x0100", eReadWrite},
	{0xB00F,	0x15, "0x0100", eReadWrite},
	{0xB010,	0xA9, "0x0100", eReadWrite},
	{0xB011,	0x16, "0x0100", eReadWrite},
	{0xB012,	0xA9, "0x0100", eReadWrite},
	{0xB013,	0x17, "0x0100", eReadWrite},
	{0xB014,	0xA9, "0x0100", eReadWrite},
	{0xB015,	0x18, "0x0100", eReadWrite},
	{0xB016,	0xA9, "0x0100", eReadWrite},
	{0xB017,	0x19, "0x0100", eReadWrite},

	{0x0000,   0x00, "eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_fourlane_resolution_2104_1560[] =
{

	{0x0112,	0x0A, "0x0100", eReadWrite},
	{0x0113,	0x0A, "0x0100", eReadWrite},
	{0x0114,	0x03, "0x0100", eReadWrite},
	{0x0301,	0x05, "0x0100", eReadWrite},
	{0x0303,	0x02, "0x0100", eReadWrite},
	{0x0305,	0x0c, "0x0100", eReadWrite},
	{0x0306,	0x04, "0x0100", eReadWrite},
	{0x0307,	0xb0, "0x0100", eReadWrite},
	{0x0309,	0x0A, "0x0100", eReadWrite},
	{0x030B,	0x01, "0x0100", eReadWrite},
	{0x030D,	0x0C, "0x0100", eReadWrite},
	{0x030E,	0x05, "0x0100", eReadWrite},
	{0x030F,	0x14, "0x0100", eReadWrite},
	{0x0310,	0x00, "0x0100", eReadWrite},
	{0x3041,	0x01, "0x0100", eReadWrite},
	{0x0342,	0x13, "0x0100", eReadWrite},
	{0x0343,	0x70, "0x0100", eReadWrite},
	{0x0340,	0x06, "0x0100", eReadWrite},
	{0x0341,	0x40, "0x0100", eReadWrite},
	{0x0344,	0x00, "0x0100", eReadWrite},
	{0x0345,	0x00, "0x0100", eReadWrite},
	{0x0346,	0x00, "0x0100", eReadWrite},
	{0x0347,	0x00, "0x0100", eReadWrite},
	{0x0348,	0x10, "0x0100", eReadWrite},
	{0x0349,	0x6F, "0x0100", eReadWrite},
	{0x034A,	0x0C, "0x0100", eReadWrite},
	{0x034B,	0x2F, "0x0100", eReadWrite},
	{0x0381,	0x01, "0x0100", eReadWrite},
	{0x0383,	0x01, "0x0100", eReadWrite},
	{0x0385,	0x01, "0x0100", eReadWrite},
	{0x0387,	0x01, "0x0100", eReadWrite},
	{0x0900,	0x01, "0x0100", eReadWrite},
	{0x0901,	0x12, "0x0100", eReadWrite},
	{0x0401,	0x01, "0x0100", eReadWrite},
	{0x0404,	0x00, "0x0100", eReadWrite},
	{0x0405,	0x20, "0x0100", eReadWrite},
	{0x0408,	0x00, "0x0100", eReadWrite},
	{0x0409,	0x02, "0x0100", eReadWrite},
	{0x040A,	0x00, "0x0100", eReadWrite},
	{0x040B,	0x00, "0x0100", eReadWrite},
	{0x040C,	0x10, "0x0100", eReadWrite},
	{0x040D,	0x6A, "0x0100", eReadWrite},
	{0x040E,	0x06, "0x0100", eReadWrite},
	{0x040F,	0x18, "0x0100", eReadWrite},
	{0x3038,	0x00, "0x0100", eReadWrite},
	{0x303A,	0x00, "0x0100", eReadWrite},
	{0x303B,	0x10, "0x0100", eReadWrite},
	{0x034C,	0x08, "0x0100", eReadWrite},//X_OUT_SIZE
	{0x034D,	0x38, "0x0100", eReadWrite},//0x34//X_OUT_SIZE
	{0x034E,	0x06, "0x0100", eReadWrite},
	{0x034F,	0x18, "0x0100", eReadWrite},
	{0x3029,	0x01, "0x0100", eReadWrite},
	{0x3A00,	0x01, "0x0100", eReadWrite},
	{0x3A01,	0x01, "0x0100", eReadWrite},
	{0x3A02,	0x05, "0x0100", eReadWrite},
	{0x3A03,	0x05, "0x0100", eReadWrite},
	{0x3A04,	0x05, "0x0100", eReadWrite},
	{0x3A05,	0xF8, "0x0100", eReadWrite},
	{0x3A06,	0x40, "0x0100", eReadWrite},
	{0x3A07,	0xFE, "0x0100", eReadWrite},
	{0x3A08,	0x10, "0x0100", eReadWrite},
	{0x3A09,	0x14, "0x0100", eReadWrite},
	{0x3A0A,	0xFE, "0x0100", eReadWrite},
	{0x3A0B,	0x44, "0x0100", eReadWrite},
	{0x0202,	0x06, "0x0100", eReadWrite},
	{0x0203,	0x36, "0x0100", eReadWrite},
	{0x0204,	0x00, "0x0100", eReadWrite},
	{0x0205,	0x00, "0x0100", eReadWrite},
	{0x020E,	0x01, "0x0100", eReadWrite},
	{0x020F,	0x00, "0x0100", eReadWrite},

	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_2104x1560P60_fourlane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_2104x1560P50_fourlane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_2104x1560P40_fourlane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_2104x1560P30_fourlane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_2104x1560P20_fourlane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_2104x1560P10_fourlane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_fourlane_resolution_4208_3120[] =
{
	{0x0112,	0x0A, "0x0100", eReadWrite},
	{0x0113,	0x0A, "0x0100", eReadWrite},
	{0x0114,	0x03, "0x0100", eReadWrite},
	//clock setting
	{0x0301,	0x05, "0x0100", eReadWrite},
	{0x0303,	0x02, "0x0100", eReadWrite},
	{0x0305,	0x0C, "0x0100", eReadWrite},
	{0x0306,	0x04, "0x0100", eReadWrite},
	{0x0307,	0xB0, "0x0100", eReadWrite},
	{0x0309,	0x0A, "0x0100", eReadWrite},
	{0x030B,	0x01, "0x0100", eReadWrite},
	{0x030D,	0x0C, "0x0100", eReadWrite},
	{0x030E,	0x05, "0x0100", eReadWrite},
	{0x030F,	0x14, "0x0100", eReadWrite},
	{0x0310,	0x00, "0x0100", eReadWrite},
	{0x3041,	0x01, "0x0100", eReadWrite},
	//line length setting
	{0x0342, 0x13, "0x0100", eReadWrite},
	{0x0343, 0x70, "0x0100", eReadWrite},
	//frame length setting
	{0x0340,	0x0C, "0x0100", eReadWrite},
	{0x0341,	0x80, "0x0100", eReadWrite},
	//ROI setting
	{0x0344,	0x00, "0x0100", eReadWrite},
	{0x0345,	0x00, "0x0100", eReadWrite},
	{0x0346,	0x00, "0x0100", eReadWrite},
	{0x0347,	0x00, "0x0100", eReadWrite},
	{0x0348,	0x10, "0x0100", eReadWrite},
	{0x0349,	0x6F, "0x0100", eReadWrite},
	{0x034A,	0x0C, "0x0100", eReadWrite},
	{0x034B,	0x2F, "0x0100", eReadWrite},
	{0x0381,	0x01, "0x0100", eReadWrite},
	{0x0383,	0x01, "0x0100", eReadWrite},
	{0x0385,	0x01, "0x0100", eReadWrite},
	{0x0387,	0x01, "0x0100", eReadWrite},
	{0x0900,	0x00, "0x0100", eReadWrite},
	{0x0901,	0x11, "0x0100", eReadWrite},
	{0x0401,	0x00, "0x0100", eReadWrite},
	{0x0404,	0x00, "0x0100", eReadWrite},
	{0x0405,	0x10, "0x0100", eReadWrite},
	{0x0408,	0x00, "0x0100", eReadWrite},
	{0x0409,	0x00, "0x0100", eReadWrite},
	{0x040A,	0x00, "0x0100", eReadWrite},
	{0x040B,	0x00, "0x0100", eReadWrite},
	{0x040C,	0x10, "0x0100", eReadWrite},
	{0x040D,	0x70, "0x0100", eReadWrite},
	{0x040E,	0x0C, "0x0100", eReadWrite},
	{0x040F,	0x30, "0x0100", eReadWrite},
	{0x3038,	0x00, "0x0100", eReadWrite},
	{0x303A,	0x00, "0x0100", eReadWrite},
	{0x303B,	0x10, "0x0100", eReadWrite},
	{0x034C,	0x10, "0x0100", eReadWrite},
	{0x034D,	0x70, "0x0100", eReadWrite},
	{0x034E,	0x0C, "0x0100", eReadWrite},
	{0x034F,	0x30, "0x0100", eReadWrite},
	{0x3029,	0x00, "0x0100", eReadWrite},
	{0x3A00,	0x00, "0x0100", eReadWrite},
	{0x3A01,	0x00, "0x0100", eReadWrite},
	{0x3A02,	0x05, "0x0100", eReadWrite},
	{0x3A03,	0x05, "0x0100", eReadWrite},
	{0x3A04,	0x05, "0x0100", eReadWrite},
	{0x3A05,	0xF8, "0x0100", eReadWrite},
	{0x3A06,	0x40, "0x0100", eReadWrite},
	{0x3A07,	0xFE, "0x0100", eReadWrite},
	{0x3A08,	0x10, "0x0100", eReadWrite},
	{0x3A09,	0x14, "0x0100", eReadWrite},
	{0x3A0A,	0xFE, "0x0100", eReadWrite},
	{0x3A0B,	0x44, "0x0100", eReadWrite},
	{0x0202,	0x0C, "0x0100", eReadWrite},
	{0x0203,	0x76, "0x0100", eReadWrite},
	{0x0204,	0x00, "0x0100", eReadWrite},
	{0x0205,	0x00, "0x0100", eReadWrite},
	{0x020E,	0x01, "0x0100", eReadWrite},
	{0x020F,	0x00, "0x0100", eReadWrite},

	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_4208x3120P30_fourlane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_4208x3120P20_fourlane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_4208x3120P10_fourlane_fpschg[] =
{
	{0x0000,   0x00, "eTableEnd",eTableEnd}
};


const IsiRegDescription_t Sensor_g_aRegDescription_twolane[] =
{
	{0x0100,	0x00, "0x0100", eReadWrite},

	{0x0136,0x0C, "0x0100", eReadWrite},
	{0x0137,0x00, "0x0100", eReadWrite},
	{0x3042,0x01, "0x0100", eReadWrite},
	{0x5CE8,0x00, "0x0100", eReadWrite},
	{0x5CE9,0x91, "0x0100", eReadWrite},
	{0x5CEA,0x00, "0x0100", eReadWrite},
	{0x5CEB,0x2A, "0x0100", eReadWrite},
	{0x5F1B,0x01, "0x0100", eReadWrite},
	{0x5C2C,0x01, "0x0100", eReadWrite},
	{0x5C2D,0xFF, "0x0100", eReadWrite},
	{0x5C2E,0x00, "0x0100", eReadWrite},
	{0x5C2F,0x00, "0x0100", eReadWrite},
	{0x5F0D,0x6E, "0x0100", eReadWrite},
	{0x5F0E,0x7C, "0x0100", eReadWrite},
	{0x5F0F,0x14, "0x0100", eReadWrite},
	{0x6100,0x30, "0x0100", eReadWrite},
	{0x6101,0x12, "0x0100", eReadWrite},
	{0x6102,0x14, "0x0100", eReadWrite},
	{0x6104,0x91, "0x0100", eReadWrite},
	{0x6105,0x30, "0x0100", eReadWrite},
	{0x6106,0x11, "0x0100", eReadWrite},
	{0x6107,0x12, "0x0100", eReadWrite},
	{0x6505,0xC4, "0x0100", eReadWrite},
	{0x6507,0x25, "0x0100", eReadWrite},
	{0x6508,0xE1, "0x0100", eReadWrite},
	{0x6509,0xD7, "0x0100", eReadWrite},
	{0x650A,0x20, "0x0100", eReadWrite},
	{0x7382,0x01, "0x0100", eReadWrite},
	{0x7383,0x13, "0x0100", eReadWrite},
	{0x7788,0x04, "0x0100", eReadWrite},
	{0x9006,0x0C, "0x0100", eReadWrite},
	{0xB000,0x78, "0x0100", eReadWrite},
	{0xB001,0xB6, "0x0100", eReadWrite},
	{0xB002,0x78, "0x0100", eReadWrite},
	{0xB003,0xB7, "0x0100", eReadWrite},
	{0xB004,0x98, "0x0100", eReadWrite},
	{0xB005,0x00, "0x0100", eReadWrite},
	{0xB006,0x98, "0x0100", eReadWrite},
	{0xB007,0x01, "0x0100", eReadWrite},
	{0xB008,0x98, "0x0100", eReadWrite},
	{0xB009,0x02, "0x0100", eReadWrite},
	{0xB00A,0xA9, "0x0100", eReadWrite},
	{0xB00B,0x0F, "0x0100", eReadWrite},
	{0xB00C,0xA9, "0x0100", eReadWrite},
	{0xB00D,0x12, "0x0100", eReadWrite},
	{0xB00E,0xA9, "0x0100", eReadWrite},
	{0xB00F,0x15, "0x0100", eReadWrite},
	{0xB010,0xA9, "0x0100", eReadWrite},
	{0xB011,0x16, "0x0100", eReadWrite},
	{0xB012,0xA9, "0x0100", eReadWrite},
	{0xB013,0x17, "0x0100", eReadWrite},
	{0xB014,0xA9, "0x0100", eReadWrite},
	{0xB015,0x18, "0x0100", eReadWrite},
	{0xB016,0xA9, "0x0100", eReadWrite},
	{0xB017,0x19, "0x0100", eReadWrite},

	{0x0000,   0x00, "eTableEnd",eTableEnd}

};


const IsiRegDescription_t Sensor_g_twolane_resolution_2104_1560[] =
{
	{0x0112,	0x0A, "0x0100", eReadWrite},
	{0x0113,	0x0A, "0x0100", eReadWrite},
	{0x0114,	0x01, "0x0100", eReadWrite},
	{0x0301,	0x05, "0x0100", eReadWrite},
	{0x0303,	0x02, "0x0100", eReadWrite},
	{0x0305,	0x0C, "0x0100", eReadWrite},
	{0x0306,	0x02, "0x0100", eReadWrite},
	{0x0307,	0x58, "0x0100", eReadWrite},
	{0x0309,	0x0A, "0x0100", eReadWrite},
	{0x030B,	0x01, "0x0100", eReadWrite},
	{0x030D,	0x0C, "0x0100", eReadWrite},
	{0x030E,	0x05, "0x0100", eReadWrite},
	{0x030F,	0x14, "0x0100", eReadWrite},
	{0x0310,	0x00, "0x0100", eReadWrite},
	{0x3041,	0x01, "0x0100", eReadWrite},
	{0x0342,	0x26, "0x0100", eReadWrite},
	{0x0343,	0xE0, "0x0100", eReadWrite},
	{0x0340,	0x06, "0x0100", eReadWrite},
	{0x0341,	0x44, "0x0100", eReadWrite},
	{0x0344,	0x00, "0x0100", eReadWrite},
	{0x0345,	0x00, "0x0100", eReadWrite},
	{0x0346,	0x00, "0x0100", eReadWrite},
	{0x0347,	0x00, "0x0100", eReadWrite},
	{0x0348,	0x10, "0x0100", eReadWrite},
	{0x0349,	0x6F, "0x0100", eReadWrite},
	{0x034A,	0x0C, "0x0100", eReadWrite},
	{0x034B,	0x2F, "0x0100", eReadWrite},
	{0x0381,	0x01, "0x0100", eReadWrite},
	{0x0383,	0x01, "0x0100", eReadWrite},
	{0x0385,	0x01, "0x0100", eReadWrite},
	{0x0387,	0x01, "0x0100", eReadWrite},
	{0x0900,	0x01, "0x0100", eReadWrite},
	{0x0901,	0x12, "0x0100", eReadWrite},
	{0x0401,	0x01, "0x0100", eReadWrite},
	{0x0404,	0x00, "0x0100", eReadWrite},
	{0x0405,	0x1F, "0x0100", eReadWrite},
	{0x0408,	0x00, "0x0100", eReadWrite},
	{0x0409,	0x40, "0x0100", eReadWrite},
	{0x040A,	0x00, "0x0100", eReadWrite},
	{0x040B,	0x00, "0x0100", eReadWrite},
	{0x040C,	0x0F, "0x0100", eReadWrite},
	{0x040D,	0xEE, "0x0100", eReadWrite},
	{0x040E,	0x06, "0x0100", eReadWrite},
	{0x040F,	0x18, "0x0100", eReadWrite},
	{0x3038,	0x00, "0x0100", eReadWrite},
	{0x303A,	0x00, "0x0100", eReadWrite},
	{0x303B,	0x10, "0x0100", eReadWrite},
	{0x034C,	0x08, "0x0100", eReadWrite},
	{0x034D,	0x38, "0x0100", eReadWrite},
	{0x034E,	0x06, "0x0100", eReadWrite},
	{0x034F,	0x18, "0x0100", eReadWrite},
	{0x3029,	0x01, "0x0100", eReadWrite},
	{0x3A00,	0x01, "0x0100", eReadWrite},
	{0x3A01,	0x01, "0x0100", eReadWrite},
	{0x3A02,	0x05, "0x0100", eReadWrite},
	{0x3A03,	0x05, "0x0100", eReadWrite},
	{0x3A04,	0x05, "0x0100", eReadWrite},
	{0x3A05,	0xF8, "0x0100", eReadWrite},
	{0x3A06,	0x40, "0x0100", eReadWrite},
	{0x3A07,	0xFE, "0x0100", eReadWrite},
	{0x3A08,	0x10, "0x0100", eReadWrite},
	{0x3A09,	0x14, "0x0100", eReadWrite},
	{0x3A0A,	0xFE, "0x0100", eReadWrite},
	{0x3A0B,	0x44, "0x0100", eReadWrite},
	{0x0202,	0x06, "0x0100", eReadWrite},
	{0x0203,	0x3A, "0x0100", eReadWrite},
	{0x0204,	0x00, "0x0100", eReadWrite},
	{0x0205,	0x00, "0x0100", eReadWrite},
	{0x020E,	0x01, "0x0100", eReadWrite},
	{0x020F,	0x00, "0x0100", eReadWrite},

    {0x0000,    0x00, "eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_2104x1560P30_twolane_fpschg[] =
{
	{0x0000,   0x00, "eTableEnd",eTableEnd}
};



const IsiRegDescription_t Sensor_g_2104x1560P25_twolane_fpschg[] =
{
	{0x0000,   0x00, "eTableEnd",eTableEnd}
};


const IsiRegDescription_t Sensor_g_2104x1560P20_twolane_fpschg[] =
{
	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_2104x1560P15_twolane_fpschg[] =
{
	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_2104x1560P10_twolane_fpschg[] =
{
	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_twolane_resolution_4208_3120[] =
{
	{0x0112,	0x0A, "0x0100", eReadWrite},
	{0x0113,	0x0A, "0x0100", eReadWrite},
	{0x0114,	0x01, "0x0100", eReadWrite},
	{0x0301,	0x05, "0x0100", eReadWrite},
	{0x0303,	0x02, "0x0100", eReadWrite},
	{0x0305,	0x0C, "0x0100", eReadWrite},
	{0x0306,	0x02, "0x0100", eReadWrite},
	{0x0307,	0x58, "0x0100", eReadWrite},
	{0x0309,	0x0A, "0x0100", eReadWrite},
	{0x030B,	0x01, "0x0100", eReadWrite},
	{0x030D,	0x0C, "0x0100", eReadWrite},
	{0x030E,	0x05, "0x0100", eReadWrite},
	{0x030F,	0x14, "0x0100", eReadWrite},
	{0x0310,	0x00, "0x0100", eReadWrite},
	{0x3041,	0x01, "0x0100", eReadWrite},
	{0x0342,	0x26, "0x0100", eReadWrite},
	{0x0343,	0xE0, "0x0100", eReadWrite},
	{0x0340,	0x0C, "0x0100", eReadWrite},
	{0x0341,	0x8C, "0x0100", eReadWrite},
	{0x0344,	0x00, "0x0100", eReadWrite},
	{0x0345,	0x00, "0x0100", eReadWrite},
	{0x0346,	0x00, "0x0100", eReadWrite},
	{0x0347,	0x00, "0x0100", eReadWrite},
	{0x0348,	0x10, "0x0100", eReadWrite},
	{0x0349,	0x6F, "0x0100", eReadWrite},
	{0x034A,	0x0C, "0x0100", eReadWrite},
	{0x034B,	0x2F, "0x0100", eReadWrite},
	{0x0381,	0x01, "0x0100", eReadWrite},
	{0x0383,	0x01, "0x0100", eReadWrite},
	{0x0385,	0x01, "0x0100", eReadWrite},
	{0x0387,	0x01, "0x0100", eReadWrite},
	{0x0900,	0x00, "0x0100", eReadWrite},
	{0x0901,	0x11, "0x0100", eReadWrite},
	{0x0401,	0x00, "0x0100", eReadWrite},
	{0x0404,	0x00, "0x0100", eReadWrite},
	{0x0405,	0x10, "0x0100", eReadWrite},
	{0x0408,	0x00, "0x0100", eReadWrite},
	{0x0409,	0x00, "0x0100", eReadWrite},
	{0x040A,	0x00, "0x0100", eReadWrite},
	{0x040B,	0x00, "0x0100", eReadWrite},
	{0x040C,	0x10, "0x0100", eReadWrite},
	{0x040D,	0x70, "0x0100", eReadWrite},
	{0x040E,	0x0C, "0x0100", eReadWrite},
	{0x040F,	0x30, "0x0100", eReadWrite},
	{0x3038,	0x00, "0x0100", eReadWrite},
	{0x303A,	0x00, "0x0100", eReadWrite},
	{0x303B,	0x10, "0x0100", eReadWrite},
	{0x034C,	0x10, "0x0100", eReadWrite},
	{0x034D,	0x70, "0x0100", eReadWrite},
	{0x034E,	0x0C, "0x0100", eReadWrite},
	{0x034F,	0x30, "0x0100", eReadWrite},
	{0x3029,	0x00, "0x0100", eReadWrite},
	{0x3A00,	0x00, "0x0100", eReadWrite},
	{0x3A01,	0x00, "0x0100", eReadWrite},
	{0x3A02,	0x05, "0x0100", eReadWrite},
	{0x3A03,	0x05, "0x0100", eReadWrite},
	{0x3A04,	0x05, "0x0100", eReadWrite},
	{0x3A05,	0xF8, "0x0100", eReadWrite},
	{0x3A06,	0x40, "0x0100", eReadWrite},
	{0x3A07,	0xFE, "0x0100", eReadWrite},
	{0x3A08,	0x10, "0x0100", eReadWrite},
	{0x3A09,	0x14, "0x0100", eReadWrite},
	{0x3A0A,	0xFE, "0x0100", eReadWrite},
	{0x3A0B,	0x44, "0x0100", eReadWrite},
	{0x0202,	0x0C, "0x0100", eReadWrite},
	{0x0203,	0x82, "0x0100", eReadWrite},
	{0x0204,	0x00, "0x0100", eReadWrite},
	{0x0205,	0x00, "0x0100", eReadWrite},
	{0x020E,	0x01, "0x0100", eReadWrite},
	{0x020F,	0x00, "0x0100", eReadWrite},

    {0x0000,    0x00, "eTableEnd",eTableEnd}
};


const IsiRegDescription_t Sensor_g_4208x3120P15_twolane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_4208x3120P10_twolane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_4208x3120P7_twolane_fpschg[] =
{

	{0x0000,   0x00, "eTableEnd",eTableEnd}
};

//one lane
const IsiRegDescription_t Sensor_g_aRegDescription_onelane[] =
{
	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_onelane_resolution_4208_3120[] =
{
	{0x0000, 0x00 ,"eTableEnd",eTableEnd}
};


const IsiRegDescription_t Sensor_g_onelane_resolution_2104_1560[] =
{
    {0x0000 ,0x00,"eTableEnd",eTableEnd}
};

