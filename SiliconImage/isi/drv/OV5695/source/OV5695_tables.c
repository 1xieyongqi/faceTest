//OV5695_tables.c
/*****************************************************************************/
/*!
 *  \file        OV5695_tables.c \n
 *  \version     1.0 \n
 *  \author      Meinicke \n
 *  \brief       Image-sensor-specific tables and other
 *               constant values/structures for OV13850. \n
 *
 *  \revision    $Revision: 803 $ \n
 *               $Author: $ \n
 *               $Date: 2010-02-26 16:35:22 +0100 (Fr, 26 Feb 2010) $ \n
 *               $Id: OV13850_tables.c 803 2010-02-26 15:35:22Z  $ \n
 */
/*  This is an unpublished work, the copyright in which vests in Silicon Image
 *  GmbH. The information contained herein is the property of Silicon Image GmbH
 *  and is supplied without liability for errors or omissions. No part may be
 *  reproduced or used expect as authorized by contract or other written
 *  permission. Copyright(c) Silicon Image GmbH, 2009, all rights reserved.
 */
/*****************************************************************************/
/*
#include "stdinc.h"

#if( OV5695_DRIVER_USAGE == USE_CAM_DRV_EN )
*/


#include <ebase/types.h>
#include <ebase/trace.h>
#include <ebase/builtins.h>

#include <common/return_codes.h>

#include "isi.h"
#include "isi_iss.h"
#include "isi_priv.h"
#include "OV5695_MIPI_priv.h"


/*****************************************************************************
 * DEFINES
 *****************************************************************************/


/*****************************************************************************
 * GLOBALS
 *****************************************************************************/

// Image sensor register settings default values taken from data sheet OV13850_DS_1.1_SiliconImage.pdf.
// The settings may be altered by the code in IsiSetupSensor.

//two lane
const IsiRegDescription_t Sensor_g_aRegDescription_twolane[] =
{


	{0x0103, 0x01,"0x0100",eReadWrite},
	{0x0100, 0x00,"0x0100",eReadWrite},
	{0x0300, 0x04,"0x0100",eReadWrite},
	{0x0301, 0x00,"0x0100",eReadWrite},
	{0x0302, 0x69,"0x0100",eReadWrite},
	{0x0303, 0x00,"0x0100",eReadWrite},
	{0x0304, 0x00,"0x0100",eReadWrite},
	{0x0305, 0x01,"0x0100",eReadWrite},
	{0x0307, 0x00,"0x0100",eReadWrite},
	{0x030b, 0x00,"0x0100",eReadWrite},
	{0x030c, 0x00,"0x0100",eReadWrite},
	{0x030d, 0x1e,"0x0100",eReadWrite},
	{0x030e, 0x04,"0x0100",eReadWrite},
	{0x030f, 0x03,"0x0100",eReadWrite},
	{0x0312, 0x01,"0x0100",eReadWrite},
	{0x3000, 0x00,"0x0100",eReadWrite},
	{0x3002, 0x21,"0x0100",eReadWrite},
	{0x3022, 0x51,"0x0100",eReadWrite},
	{0x3106, 0x15,"0x0100",eReadWrite},
	{0x3107, 0x01,"0x0100",eReadWrite},
	{0x3108, 0x05,"0x0100",eReadWrite},
	{0x3500, 0x00,"0x0100",eReadWrite},
	{0x3501, 0x45,"0x0100",eReadWrite},
	{0x3502, 0x00,"0x0100",eReadWrite},
	{0x3503, 0x08,"0x0100",eReadWrite},
	{0x3504, 0x03,"0x0100",eReadWrite},
	{0x3505, 0x8c,"0x0100",eReadWrite},
	{0x3507, 0x03,"0x0100",eReadWrite},
	{0x3508, 0x00,"0x0100",eReadWrite},
	{0x3509, 0x10,"0x0100",eReadWrite},
	{0x350c, 0x00,"0x0100",eReadWrite},
	//{0x3500, 0x00,"0x0100",eReadWrite},
	//{0x3501, 0x3d,"0x0100",eReadWrite},
	//{0x3502, 0x00,"0x0100",eReadWrite},
	{0x350d, 0x80,"0x0100",eReadWrite},
	//{0x350a, 0x00,"0x0100",eReadWrite},
	//{0x350b, 0x40,"0x0100",eReadWrite},
	{0x3510, 0x00,"0x0100",eReadWrite},
	{0x3511, 0x02,"0x0100",eReadWrite},
	{0x3512, 0x00,"0x0100",eReadWrite},
	{0x3601, 0x55,"0x0100",eReadWrite},
	{0x3602, 0x58,"0x0100",eReadWrite},
	{0x3614, 0x30,"0x0100",eReadWrite},
	{0x3615, 0x77,"0x0100",eReadWrite},
	{0x3621, 0x08,"0x0100",eReadWrite},
	{0x3624, 0x40,"0x0100",eReadWrite},
	{0x3633, 0x0c,"0x0100",eReadWrite},
	{0x3634, 0x0c,"0x0100",eReadWrite},
	{0x3635, 0x0c,"0x0100",eReadWrite},
	{0x3636, 0x0c,"0x0100",eReadWrite},
	{0x3638, 0x00,"0x0100",eReadWrite},
	{0x3639, 0x00,"0x0100",eReadWrite},
	{0x363a, 0x00,"0x0100",eReadWrite},
	{0x363b, 0x00,"0x0100",eReadWrite},
	{0x363c, 0xff,"0x0100",eReadWrite},
	{0x363d, 0xfa,"0x0100",eReadWrite},
	{0x3650, 0x44,"0x0100",eReadWrite},
	{0x3651, 0x44,"0x0100",eReadWrite},
	{0x3652, 0x44,"0x0100",eReadWrite},
	{0x3653, 0x44,"0x0100",eReadWrite},
	{0x3654, 0x44,"0x0100",eReadWrite},
	{0x3655, 0x44,"0x0100",eReadWrite},
	{0x3656, 0x44,"0x0100",eReadWrite},
	{0x3657, 0x44,"0x0100",eReadWrite},
	{0x3660, 0x00,"0x0100",eReadWrite},
	{0x3661, 0x00,"0x0100",eReadWrite},
	{0x3662, 0x00,"0x0100",eReadWrite},
	{0x366a, 0x00,"0x0100",eReadWrite},
	{0x366e, 0x0c,"0x0100",eReadWrite},
	{0x3673, 0x04,"0x0100",eReadWrite},
	{0x3700, 0x14,"0x0100",eReadWrite},
	{0x3703, 0x0c,"0x0100",eReadWrite},
	{0x3715, 0x01,"0x0100",eReadWrite},
	{0x3733, 0x10,"0x0100",eReadWrite},
	{0x3734, 0x40,"0x0100",eReadWrite},
	{0x373f, 0xa0,"0x0100",eReadWrite},
	{0x3765, 0x20,"0x0100",eReadWrite},
	{0x37a1, 0x1d,"0x0100",eReadWrite},
	{0x37a8, 0x26,"0x0100",eReadWrite},
	{0x37ab, 0x14,"0x0100",eReadWrite},
	{0x37c2, 0x04,"0x0100",eReadWrite},
	{0x37cb, 0x09,"0x0100",eReadWrite},
	{0x37cc, 0x13,"0x0100",eReadWrite},
	{0x37cd, 0x1f,"0x0100",eReadWrite},
	{0x37ce, 0x1f,"0x0100",eReadWrite},
	{0x3800, 0x00,"0x0100",eReadWrite},
	{0x3801, 0x00,"0x0100",eReadWrite},
	{0x3802, 0x00,"0x0100",eReadWrite},
	{0x3803, 0x00,"0x0100",eReadWrite},
	{0x3804, 0x0a,"0x0100",eReadWrite},
	{0x3805, 0x3f,"0x0100",eReadWrite},
	{0x3806, 0x07,"0x0100",eReadWrite},
	{0x3807, 0xaf,"0x0100",eReadWrite},
	{0x3808, 0x05,"0x0100",eReadWrite},
	{0x3809, 0x10,"0x0100",eReadWrite},
	{0x380a, 0x03,"0x0100",eReadWrite},
	{0x380b, 0xcc,"0x0100",eReadWrite},
	{0x380c, 0x02,"0x0100",eReadWrite},
	{0x380d, 0xa0,"0x0100",eReadWrite},
	{0x380e, 0x08,"0x0100",eReadWrite},
	{0x380f, 0xb8,"0x0100",eReadWrite},
	{0x3810, 0x00,"0x0100",eReadWrite},
	{0x3811, 0x06,"0x0100",eReadWrite},
	{0x3812, 0x00,"0x0100",eReadWrite},
	{0x3813, 0x06,"0x0100",eReadWrite},
	{0x3814, 0x03,"0x0100",eReadWrite},
	{0x3815, 0x01,"0x0100",eReadWrite},
	{0x3816, 0x03,"0x0100",eReadWrite},
	{0x3817, 0x01,"0x0100",eReadWrite},
	{0x3818, 0x00,"0x0100",eReadWrite},
	{0x3819, 0x00,"0x0100",eReadWrite},
	{0x381a, 0x00,"0x0100",eReadWrite},
	{0x381b, 0x01,"0x0100",eReadWrite},
	{0x3820, 0x8b,"0x0100",eReadWrite},
	{0x3821, 0x01,"0x0100",eReadWrite},
	{0x3c80, 0x08,"0x0100",eReadWrite},
	{0x3c82, 0x00,"0x0100",eReadWrite},
	{0x3c83, 0x00,"0x0100",eReadWrite},
	{0x3c88, 0x00,"0x0100",eReadWrite},
	{0x3d85, 0x14,"0x0100",eReadWrite},
	{0x3f02, 0x08,"0x0100",eReadWrite},
	{0x3f03, 0x10,"0x0100",eReadWrite},
	{0x4008, 0x02,"0x0100",eReadWrite},
	{0x4009, 0x09,"0x0100",eReadWrite},
	{0x404e, 0x20,"0x0100",eReadWrite},
	{0x4501, 0x00,"0x0100",eReadWrite},
	{0x4502, 0x10,"0x0100",eReadWrite},
	{0x4800, 0x00,"0x0100",eReadWrite},
	{0x481f, 0x2a,"0x0100",eReadWrite},
	{0x4837, 0x13,"0x0100",eReadWrite},
	{0x5000, 0x17,"0x0100",eReadWrite},
	{0x5780, 0x3e,"0x0100",eReadWrite},
	{0x5781, 0x0f,"0x0100",eReadWrite},
	{0x5782, 0x44,"0x0100",eReadWrite},
	{0x5783, 0x02,"0x0100",eReadWrite},
	{0x5784, 0x01,"0x0100",eReadWrite},
	{0x5785, 0x01,"0x0100",eReadWrite},
	{0x5786, 0x00,"0x0100",eReadWrite},
	{0x5787, 0x04,"0x0100",eReadWrite},
	{0x5788, 0x02,"0x0100",eReadWrite},
	{0x5789, 0x0f,"0x0100",eReadWrite},
	{0x578a, 0xfd,"0x0100",eReadWrite},
	{0x578b, 0xf5,"0x0100",eReadWrite},
	{0x578c, 0xf5,"0x0100",eReadWrite},
	{0x578d, 0x03,"0x0100",eReadWrite},
	{0x578e, 0x08,"0x0100",eReadWrite},
	{0x578f, 0x0c,"0x0100",eReadWrite},
	{0x5790, 0x08,"0x0100",eReadWrite},
	{0x5791, 0x06,"0x0100",eReadWrite},
	{0x5792, 0x00,"0x0100",eReadWrite},
	{0x5793, 0x52,"0x0100",eReadWrite},
	{0x5794, 0xa3,"0x0100",eReadWrite},
	{0x5b00, 0x00,"0x0100",eReadWrite},
	{0x5b01, 0x1c,"0x0100",eReadWrite},
	{0x5b02, 0x00,"0x0100",eReadWrite},
	{0x5b03, 0x7f,"0x0100",eReadWrite},
	{0x5b05, 0x6c,"0x0100",eReadWrite},
	{0x5e10, 0xfc,"0x0100",eReadWrite},
	{0x4010, 0xf1,"0x0100",eReadWrite},
	{0x3503, 0x08,"0x0100",eReadWrite},
	{0x3505, 0x8c,"0x0100",eReadWrite},
	{0x3507, 0x03,"0x0100",eReadWrite},
	{0x3508, 0x00,"0x0100",eReadWrite},
	{0x3509, 0xf8,"0x0100",eReadWrite},
	//{0x3811, 0x06,"0x0100",eReadWrite},
	//{0x5b03, 0xf0,"0x0100",eReadWrite},
	//{0x0100, 0x01,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_twolane_resolution_1296_972[] =
{

	{0x5301, 0x45,"0x0100",eReadWrite},
	{0x366e, 0x0c,"0x0100",eReadWrite},
	{0x3800, 0x00,"0x0100",eReadWrite}, // xstart = 0
	{0x3801, 0x00,"0x0100",eReadWrite}, // x start
	{0x3802, 0x00,"0x0100",eReadWrite}, // y start = 0
	{0x3803, 0x00,"0x0100",eReadWrite}, // y start
	{0x3804, 0x0a,"0x0100",eReadWrite}, // xend = 2623
	{0x3805, 0x3f,"0x0100",eReadWrite}, // xend
	{0x3806, 0x07,"0x0100",eReadWrite}, // yend = 1955
	{0x3807, 0xaf,"0x0100",eReadWrite}, // yend
	{0x3808, 0x05,"0x0100",eReadWrite}, // x output size = 1296
	{0x3809, 0x10,"0x0100",eReadWrite}, // x output size
	{0x380a, 0x03,"0x0100",eReadWrite}, // y output size = 972
	{0x380b, 0xcc,"0x0100",eReadWrite}, // y output size
	{0x380c, 0x02,"0x0100",eReadWrite},
	{0x380d, 0xa0,"0x0100",eReadWrite},
	{0x380e, 0x08,"0x0100",eReadWrite},
	{0x380f, 0xb8,"0x0100",eReadWrite},
	{0x3811, 0x06,"0x0100",eReadWrite}, // isp x win
	{0x3813, 0x06,"0x0100",eReadWrite}, // isp y win
	{0x3814, 0x03,"0x0100",eReadWrite}, // x inc
	{0x3816, 0x03,"0x0100",eReadWrite}, // y inc
	{0x3817, 0x01,"0x0100",eReadWrite}, // hsync start
	{0x3820, 0x8b,"0x0100",eReadWrite}, // flip off, v bin off
	{0x3821, 0x01,"0x0100",eReadWrite}, // mirror on, h bin on
	{0x4501, 0x00,"0x0100",eReadWrite}, // black line number
	{0x4008, 0x02,"0x0100",eReadWrite}, // blc level trigger
	//{0x350b, 0x80,"0x0100",eReadWrite}, // gain = 8x
	{0x4009, 0x09,"0x0100",eReadWrite}, // MIPI global timing
	//{0x0100, 0x01,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};


const IsiRegDescription_t Sensor_g_twolane_resolution_2592_1944[] =
{

	{0x3501, 0x7e,"0x0100",eReadWrite},
	{0x366e, 0x18,"0x0100",eReadWrite},
	{0x3800, 0x00,"0x0100",eReadWrite},
	{0x3801, 0x00,"0x0100",eReadWrite},
	{0x3802, 0x00,"0x0100",eReadWrite},
	{0x3803, 0x04,"0x0100",eReadWrite},
	{0x3804, 0x0a,"0x0100",eReadWrite},
	{0x3805, 0x3f,"0x0100",eReadWrite},
	{0x3806, 0x07,"0x0100",eReadWrite},
	{0x3807, 0xab,"0x0100",eReadWrite},
	{0x3808, 0x0a,"0x0100",eReadWrite},
	{0x3809, 0x20,"0x0100",eReadWrite},
	{0x380a, 0x07,"0x0100",eReadWrite},
	{0x380b, 0x98,"0x0100",eReadWrite},
	{0x380c, 0x02,"0x0100",eReadWrite},
	{0x380d, 0xe4,"0x0100",eReadWrite},
	{0x380e, 0x07,"0x0100",eReadWrite},
	{0x380f, 0xe8,"0x0100",eReadWrite},
	{0x3811, 0x06,"0x0100",eReadWrite},
	{0x3813, 0x08,"0x0100",eReadWrite},
	{0x3814, 0x01,"0x0100",eReadWrite},
	{0x3816, 0x01,"0x0100",eReadWrite},
	{0x3817, 0x01,"0x0100",eReadWrite},
	{0x3820, 0x88,"0x0100",eReadWrite},
	{0x3821, 0x00,"0x0100",eReadWrite},
	{0x4501, 0x00,"0x0100",eReadWrite},
	{0x4008, 0x04,"0x0100",eReadWrite},
	{0x4009, 0x13,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_1296x972P30_twolane_fpschg[] =
{
	{0x380e, 0x08,"0x0100",eReadWrite},
	{0x380f, 0xb8,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_1296x972P25_twolane_fpschg[] =
{
	{0x380e, 0xa,"0x0100",eReadWrite},
	{0x380f, 0x76,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};


const IsiRegDescription_t Sensor_g_1296x972P20_twolane_fpschg[] =
{
	{0x380e, 0xd,"0x0100",eReadWrite},
	{0x380f, 0x14,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};


const IsiRegDescription_t Sensor_g_1296x972P15_twolane_fpschg[] =
{
	{0x380e, 0x11,"0x0100",eReadWrite},
	{0x380f, 0x70,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_1296x972P10_twolane_fpschg[] =
{
	{0x380e, 0x1a,"0x0100",eReadWrite},
	{0x380f, 0x28,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};



const IsiRegDescription_t Sensor_g_2592x1944P30_twolane_fpschg[] =
{
	{0x380e, 0x07,"0x0100",eReadWrite},
	{0x380f, 0xe8,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};


const IsiRegDescription_t Sensor_g_2592x1944P15_twolane_fpschg[] =
{
	{0x380e, 0x0f,"0x0100",eReadWrite},
	{0x380f, 0xd0,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};
const IsiRegDescription_t Sensor_g_2592x1944P7_twolane_fpschg[] =
{
	{0x380e, 0x1f,"0x0100",eReadWrite},
	{0x380f, 0xa0,"0x0100",eReadWrite},

	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};
