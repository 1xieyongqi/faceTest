//OV5648_tables.c
/*****************************************************************************/
/*!
 *  \file        OV5648_tables.c \n
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

#if( OV5648_DRIVER_USAGE == USE_CAM_DRV_EN )
*/


#include <ebase/types.h>
#include <ebase/trace.h>
#include <ebase/builtins.h>

#include <common/return_codes.h>

#include "isi.h"
#include "isi_iss.h"
#include "isi_priv.h"
#include "OV5693_MIPI_priv.h"


/*****************************************************************************
 * DEFINES
 *****************************************************************************/


/*****************************************************************************
 * GLOBALS
 *****************************************************************************/

// Image sensor register settings default values taken from data sheet OV13850_DS_1.1_SiliconImage.pdf.
// The settings may be altered by the code in IsiSetupSensor.

//four lane
const IsiRegDescription_t Sensor_g_aRegDescription_fourlane[] =
{

	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_fourlane_resolution_1296_972[] =
{

	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};


const IsiRegDescription_t Sensor_g_fourlane_resolution_2592_1944[] =
{

	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};


//two lane
const IsiRegDescription_t Sensor_g_aRegDescription_twolane[] =
{
	//------------------------------------@@ Init(1296x972) 30fps 2lane 10Bit
	// OV5693 setting version History										 
	//																		 
	// R2B v14																 
	// 1. 3602 from 18 to 38 for RC MODE									 
	// R2C v15																 
	// 1.update lenc setting												 
	// R2C v16																 
	// 1.adjust adc range to 18 for 240Mhz dac_clk							 
	//																		 
	//																		 
	// MIPI 2 lane, 640Mbps 												 
	// SCLK=120Mhz, DACclock = 240Mhz										 
	//																		 
	{0x0103,0x01,"0x0100",eReadWrite},// software reset 											
	{0x3001,0x0a,"0x0100",eReadWrite},// FSIN output, FREX input									
	{0x3002,0x80,"0x0100",eReadWrite},// Vsync output, Href, Frex, strobe, fsin, ilpwm input		
	{0x3006,0x00,"0x0100",eReadWrite},// output value of GPIO
	{0x3011,0x21,"0x0100",eReadWrite},// MIPI 2 lane enable
	{0x3012,0x09,"0x0100",eReadWrite},// MIPI 10-bit
	{0x3013,0x10,"0x0100",eReadWrite},// Drive 1x
	{0x3014,0x00,"0x0100",eReadWrite},//
	{0x3015,0x08,"0x0100",eReadWrite},// MIPI on
	{0x3016,0xf0,"0x0100",eReadWrite},//
	{0x3017,0xf0,"0x0100",eReadWrite},//
	{0x3018,0xf0,"0x0100",eReadWrite},//
	{0x301b,0xb4,"0x0100",eReadWrite},//
	{0x301d,0x02,"0x0100",eReadWrite},//
	{0x3021,0x00,"0x0100",eReadWrite},// internal regulator on
	{0x3022,0x01,"0x0100",eReadWrite},//
	{0x3028,0x44,"0x0100",eReadWrite},//
	{0x3098,0x03,"0x0100",eReadWrite},// PLL
	{0x3099,0x1e,"0x0100",eReadWrite},// PLL
	{0x309a,0x03,"0x0100",eReadWrite},// PLL
	{0x309b,0x01,"0x0100",eReadWrite},// PLL
	{0x309c,0x00,"0x0100",eReadWrite},// PLL
	{0x30a0,0xd2,"0x0100",eReadWrite},//
	{0x30a2,0x01,"0x0100",eReadWrite},//
	{0x30b2,0x00,"0x0100",eReadWrite},//
	{0x30b3,0x50,"0x0100",eReadWrite},// PLL
	{0x30b4,0x03,"0x0100",eReadWrite},// PLL
	{0x30b5,0x04,"0x0100",eReadWrite},// PLL
	{0x30b6,0x01,"0x0100",eReadWrite},// PLL
	{0x3104,0x21,"0x0100",eReadWrite},// sclk from dac_pll
	{0x3106,0x00,"0x0100",eReadWrite},// sclk_sel from pll_clk
	{0x3400,0x04,"0x0100",eReadWrite},// MWB R H
	{0x3401,0x00,"0x0100",eReadWrite},// MWB R L
	{0x3402,0x04,"0x0100",eReadWrite},// MWB G H
	{0x3403,0x00,"0x0100",eReadWrite},// MWB G L
	{0x3404,0x04,"0x0100",eReadWrite},// MWB B H
	{0x3405,0x00,"0x0100",eReadWrite},// MWB B L
	{0x3406,0x01,"0x0100",eReadWrite},// MWB gain enable
	{0x3500,0x00,"0x0100",eReadWrite},// exposure HH
	{0x3501,0x3d,"0x0100",eReadWrite},// exposure H
	{0x3502,0x00,"0x0100",eReadWrite},// exposure L
	{0x3503,0x07,"0x0100",eReadWrite},// gain 1 frame latch, VTS manual, AGC manual, AEC manual
	{0x3504,0x00,"0x0100",eReadWrite},// manual gain H
	{0x3505,0x00,"0x0100",eReadWrite},// manual gain L
	{0x3506,0x00,"0x0100",eReadWrite},// short exposure HH
	{0x3507,0x02,"0x0100",eReadWrite},// short exposure H
	{0x3508,0x00,"0x0100",eReadWrite},// short exposure L
	{0x3509,0x10,"0x0100",eReadWrite},// use real ggain
	{0x350a,0x00,"0x0100",eReadWrite},// gain H
	{0x350b,0x40,"0x0100",eReadWrite},// gain L
	{0x3600,0xbc,"0x0100",eReadWrite},//
	{0x3601,0x0a,"0x0100",eReadWrite},// analog
	{0x3602,0x38,"0x0100",eReadWrite},//
	{0x3612,0x80,"0x0100",eReadWrite},//
	{0x3620,0x44,"0x0100",eReadWrite},// 
	{0x3621,0xb5,"0x0100",eReadWrite},// 
	{0x3622,0x0c,"0x0100",eReadWrite},// 
	{0x3625,0x10,"0x0100",eReadWrite},//
	{0x3630,0x55,"0x0100",eReadWrite},//
	{0x3631,0xf4,"0x0100",eReadWrite},//
	{0x3632,0x00,"0x0100",eReadWrite},//
	{0x3633,0x34,"0x0100",eReadWrite},//
	{0x3634,0x02,"0x0100",eReadWrite},//
	{0x364d,0x0d,"0x0100",eReadWrite},//
	{0x364f,0xdd,"0x0100",eReadWrite},//
	{0x3660,0x04,"0x0100",eReadWrite},//
	{0x3662,0x10,"0x0100",eReadWrite},//
	{0x3663,0xf1,"0x0100",eReadWrite},//
	{0x3665,0x00,"0x0100",eReadWrite},//
	{0x3666,0x20,"0x0100",eReadWrite},//
	{0x3667,0x00,"0x0100",eReadWrite},//
	{0x366a,0x80,"0x0100",eReadWrite},//
	{0x3680,0xe0,"0x0100",eReadWrite},//
	{0x3681,0x00,"0x0100",eReadWrite},// analog
	{0x3700,0x42,"0x0100",eReadWrite},// sensor control
	{0x3701,0x14,"0x0100",eReadWrite},//
	{0x3702,0xa0,"0x0100",eReadWrite},//
	{0x3703,0xd8,"0x0100",eReadWrite},//
	{0x3704,0x78,"0x0100",eReadWrite},//
	{0x3705,0x02,"0x0100",eReadWrite},//
	{0x3708,0xe6,"0x0100",eReadWrite},//
	{0x3709,0xc7,"0x0100",eReadWrite},//
	{0x370a,0x00,"0x0100",eReadWrite},//
	{0x370b,0x20,"0x0100",eReadWrite},//
	{0x370c,0x0c,"0x0100",eReadWrite},//
	{0x370d,0x11,"0x0100",eReadWrite},//
	{0x370e,0x00,"0x0100",eReadWrite},//
	{0x370f,0x40,"0x0100",eReadWrite},//
	{0x3710,0x00,"0x0100",eReadWrite},//
	{0x371a,0x1c,"0x0100",eReadWrite},//
	{0x371b,0x05,"0x0100",eReadWrite},//
	{0x371c,0x01,"0x0100",eReadWrite},//
	{0x371e,0xa1,"0x0100",eReadWrite},//
	{0x371f,0x0c,"0x0100",eReadWrite},//
	{0x3721,0x00,"0x0100",eReadWrite},//
	{0x3724,0x10,"0x0100",eReadWrite},//
	{0x3726,0x00,"0x0100",eReadWrite},//
	{0x372a,0x01,"0x0100",eReadWrite},//
	{0x3730,0x10,"0x0100",eReadWrite},//
	{0x3738,0x22,"0x0100",eReadWrite},//
	{0x3739,0xe5,"0x0100",eReadWrite},//
	{0x373a,0x50,"0x0100",eReadWrite},//
	{0x373b,0x02,"0x0100",eReadWrite},//
	{0x373c,0x41,"0x0100",eReadWrite},//
	{0x373f,0x02,"0x0100",eReadWrite},//
	{0x3740,0x42,"0x0100",eReadWrite},//
	{0x3741,0x02,"0x0100",eReadWrite},//
	{0x3742,0x18,"0x0100",eReadWrite},//
	{0x3743,0x01,"0x0100",eReadWrite},//
	{0x3744,0x02,"0x0100",eReadWrite},//
	{0x3747,0x10,"0x0100",eReadWrite},//
	{0x374c,0x04,"0x0100",eReadWrite},//
	{0x3751,0xf0,"0x0100",eReadWrite},//
	{0x3752,0x00,"0x0100",eReadWrite},//
	{0x3753,0x00,"0x0100",eReadWrite},//
	{0x3754,0xc0,"0x0100",eReadWrite},//
	{0x3755,0x00,"0x0100",eReadWrite},//
	{0x3756,0x1a,"0x0100",eReadWrite},//
	{0x3758,0x00,"0x0100",eReadWrite},//
	{0x3759,0x0f,"0x0100",eReadWrite},//
	{0x376b,0x44,"0x0100",eReadWrite},//
	{0x375c,0x04,"0x0100",eReadWrite},//
	{0x3774,0x10,"0x0100",eReadWrite},//
	{0x3776,0x00,"0x0100",eReadWrite},//
	{0x377f,0x08,"0x0100",eReadWrite},// sensor control
	{0x3780,0x22,"0x0100",eReadWrite},// PSRAM control
	{0x3781,0x0c,"0x0100",eReadWrite},//
	{0x3784,0x2c,"0x0100",eReadWrite},//
	{0x3785,0x1e,"0x0100",eReadWrite},//
	{0x378f,0xf5,"0x0100",eReadWrite},//
	{0x3791,0xb0,"0x0100",eReadWrite},//
	{0x3795,0x00,"0x0100",eReadWrite},//
	{0x3796,0x64,"0x0100",eReadWrite},//
	{0x3797,0x11,"0x0100",eReadWrite},//
	{0x3798,0x30,"0x0100",eReadWrite},//
	{0x3799,0x41,"0x0100",eReadWrite},//
	{0x379a,0x07,"0x0100",eReadWrite},//
	{0x379b,0xb0,"0x0100",eReadWrite},//
	{0x379c,0x0c,"0x0100",eReadWrite},// PSRAM control
	{0x37c5,0x00,"0x0100",eReadWrite},// sensor FREX exp HH
	{0x37c6,0x00,"0x0100",eReadWrite},// sensor FREX exp H
	{0x37c7,0x00,"0x0100",eReadWrite},// sensor FREX exp L
	{0x37c9,0x00,"0x0100",eReadWrite},// strobe Width HH
	{0x37ca,0x00,"0x0100",eReadWrite},// strobe Width H
	{0x37cb,0x00,"0x0100",eReadWrite},// strobe Width L
	{0x37de,0x00,"0x0100",eReadWrite},// sensor FREX PCHG Width H
	{0x37df,0x00,"0x0100",eReadWrite},// sensor FREX PCHG Width L
	{0x3800,0x00,"0x0100",eReadWrite},// X start H
	{0x3801,0x00,"0x0100",eReadWrite},// X start L
	{0x3802,0x00,"0x0100",eReadWrite},// Y start H
	{0x3803,0x00,"0x0100",eReadWrite},// Y start L
	{0x3804,0x0a,"0x0100",eReadWrite},// X end H
	{0x3805,0x3f,"0x0100",eReadWrite},// X end L
	{0x3806,0x07,"0x0100",eReadWrite},// Y end H
	{0x3807,0xa3,"0x0100",eReadWrite},// Y end L
	{0x3808,0x05,"0x0100",eReadWrite},// X output size H
	{0x3809,0x10,"0x0100",eReadWrite},// X output size L
	{0x380a,0x03,"0x0100",eReadWrite},// Y output size H
	{0x380b,0xcc,"0x0100",eReadWrite},// Y output size L
	{0x380c,0x0a,"0x0100",eReadWrite},// HTS H
	{0x380d,0x80,"0x0100",eReadWrite},// HTS H
	{0x380e,0x05,"0x0100",eReadWrite},// HTS L
	{0x380f,0xd0,"0x0100",eReadWrite},// HTS L
	{0x3810,0x00,"0x0100",eReadWrite},// timing ISP x win H
	{0x3811,0x02,"0x0100",eReadWrite},// timing ISP x win L
	{0x3812,0x00,"0x0100",eReadWrite},// timing ISP y win H
	{0x3813,0x02,"0x0100",eReadWrite},// timing ISP y win L
	{0x3814,0x31,"0x0100",eReadWrite},// timing x inc
	{0x3815,0x31,"0x0100",eReadWrite},// timing y ing
	{0x3820,0x04,"0x0100",eReadWrite},// v fast bin on, v flip off, v bin off
	{0x3821,0x1f,"0x0100",eReadWrite},// hsync on, mirror on, hbin on
	{0x3823,0x00,"0x0100",eReadWrite},//
	{0x3824,0x00,"0x0100",eReadWrite},//
	{0x3825,0x00,"0x0100",eReadWrite},//
	{0x3826,0x00,"0x0100",eReadWrite},//
	{0x3827,0x00,"0x0100",eReadWrite},//
	{0x382a,0x04,"0x0100",eReadWrite},//
	{0x3a04,0x06,"0x0100",eReadWrite},//
	{0x3a05,0x14,"0x0100",eReadWrite},//
	{0x3a06,0x00,"0x0100",eReadWrite},//
	{0x3a07,0xfe,"0x0100",eReadWrite},//
	{0x3b00,0x00,"0x0100",eReadWrite},// strobe off
	{0x3b02,0x00,"0x0100",eReadWrite},// strobe dummy line H
	{0x3b03,0x00,"0x0100",eReadWrite},// strobe dummy line L
	{0x3b04,0x00,"0x0100",eReadWrite},// strobe at next frame
	{0x3b05,0x00,"0x0100",eReadWrite},// strobe pulse width
	{0x3e07,0x20,"0x0100",eReadWrite},//
	{0x4000,0x08,"0x0100",eReadWrite},//
	{0x4001,0x04,"0x0100",eReadWrite},// BLC start line
	{0x4002,0x45,"0x0100",eReadWrite},// BLC auto enable, do 5 frames
	{0x4004,0x08,"0x0100",eReadWrite},// 8 black lines
	{0x4005,0x18,"0x0100",eReadWrite},// don't output black line, apply one channel offset to all, BLC triggered by gain change,
	{0x4006,0x20,"0x0100",eReadWrite},// ZLINE COEF
	{0x4008,0x24,"0x0100",eReadWrite},// 
	{0x4009,0x10,"0x0100",eReadWrite},// black level target
	{0x400c,0x00,"0x0100",eReadWrite},// BLC man level0 H
	{0x400d,0x00,"0x0100",eReadWrite},// BLC man level0 L
	{0x4058,0x00,"0x0100",eReadWrite},//
	{0x404e,0x37,"0x0100",eReadWrite},// BLC maximum black level
	{0x404f,0x8f,"0x0100",eReadWrite},// BLC stable range
	{0x4058,0x00,"0x0100",eReadWrite},//
	{0x4101,0xb2,"0x0100",eReadWrite},//
	{0x4303,0x00,"0x0100",eReadWrite},// test pattern off
	{0x4304,0x08,"0x0100",eReadWrite},// test pattern option
	{0x4307,0x30,"0x0100",eReadWrite},// 
	{0x4311,0x04,"0x0100",eReadWrite},// Vsync width H
	{0x4315,0x01,"0x0100",eReadWrite},// Vsync width L
	{0x4511,0x05,"0x0100",eReadWrite},//
	{0x4512,0x01,"0x0100",eReadWrite},//
	{0x4806,0x00,"0x0100",eReadWrite},//
	{0x4816,0x52,"0x0100",eReadWrite},// embedded line data type
	{0x481f,0x30,"0x0100",eReadWrite},// max clk_prepare
	{0x4826,0x2c,"0x0100",eReadWrite},// hs prepare min
	{0x4831,0x64,"0x0100",eReadWrite},// UI hs prepare
	{0x4d00,0x04,"0x0100",eReadWrite},// temprature sensor
	{0x4d01,0x71,"0x0100",eReadWrite},//
	{0x4d02,0xfd,"0x0100",eReadWrite},//
	{0x4d03,0xf5,"0x0100",eReadWrite},//
	{0x4d04,0x0c,"0x0100",eReadWrite},//
	{0x4d05,0xcc,"0x0100",eReadWrite},// temperature sensor
	{0x4837,0x0d,"0x0100",eReadWrite},// MIPI global timing
	{0x5000,0x06,"0x0100",eReadWrite},// BPC on, WPC on
	{0x5001,0x01,"0x0100",eReadWrite},// MWB on
	{0x5002,0x00,"0x0100",eReadWrite},// scal off
	{0x5003,0x20,"0x0100",eReadWrite},//
	{0x5046,0x0a,"0x0100",eReadWrite},// SOF auto mode
	{0x5013,0x00,"0x0100",eReadWrite},//
	{0x5046,0x0a,"0x0100",eReadWrite},// SOF auto mode
	{0x5780,0xfc,"0x0100",eReadWrite},// DPC
	{0x5781,0x13,"0x0100",eReadWrite},//
	{0x5782,0x03,"0x0100",eReadWrite},//
	{0x5786,0x20,"0x0100",eReadWrite},//
	{0x5787,0x40,"0x0100",eReadWrite},//
	{0x5788,0x08,"0x0100",eReadWrite},//
	{0x5789,0x08,"0x0100",eReadWrite},//
	{0x578a,0x02,"0x0100",eReadWrite},//
	{0x578b,0x01,"0x0100",eReadWrite},//
	{0x578c,0x01,"0x0100",eReadWrite},//
	{0x578d,0x0c,"0x0100",eReadWrite},//
	{0x578e,0x02,"0x0100",eReadWrite},//
	{0x578f,0x01,"0x0100",eReadWrite},//
	{0x5790,0x01,"0x0100",eReadWrite},//
	{0x5791,0xff,"0x0100",eReadWrite},// DPC
	{0x5842,0x01,"0x0100",eReadWrite},// LENC BR Hscale H
	{0x5843,0x2b,"0x0100",eReadWrite},// LENC BR Hscale L
	{0x5844,0x01,"0x0100",eReadWrite},// LENC BR Vscale H
	{0x5845,0x92,"0x0100",eReadWrite},// LENC BR Vscale L
	{0x5846,0x01,"0x0100",eReadWrite},// LENC G Hscale H
	{0x5847,0x8f,"0x0100",eReadWrite},// LENC G Hscale L
	{0x5848,0x01,"0x0100",eReadWrite},// LENC G Vscale H
	{0x5849,0x0c,"0x0100",eReadWrite},// LENC G Vscale L
	{0x5e00,0x00,"0x0100",eReadWrite},// test pattern off
	{0x5e10,0x0c,"0x0100",eReadWrite},//
	//{0x0100,0x01,"0x0100",eReadWrite},// wake up
	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_twolane_resolution_1296_972[] =
{
//Preview 1296x972 30fps 24M MCLK 2lane 640Mbps/lane
	{0x0100,0x00,"0x0100",eReadWrite},// software sleep
	{0x3708,0xe6,"0x0100",eReadWrite},// sensor control
	{0x3709,0xc7,"0x0100",eReadWrite},// sensor control
	{0x3801,0x00,"0x0100",eReadWrite},// X start L
	{0x3803,0x00,"0x0100",eReadWrite},// timing Y start L
	{0x3806,0x07,"0x0100",eReadWrite},// timing Y end H
	{0x3807,0xa3,"0x0100",eReadWrite},// timing Y end L
	{0x3808,0x05,"0x0100",eReadWrite},// X output size H
	{0x3809,0x10,"0x0100",eReadWrite},// X output size L
	{0x380a,0x03,"0x0100",eReadWrite},// Y output size H
	{0x380b,0xcc,"0x0100",eReadWrite},// Y output size L
	{0x380c,0x0a,"0x0100",eReadWrite},// HTS H
	{0x380d,0x80,"0x0100",eReadWrite},// HTS L
	{0x380e,0x05,"0x0100",eReadWrite},// VTS H
	{0x380f,0xd0,"0x0100",eReadWrite},// VTS L
	{0x3810,0x00,"0x0100",eReadWrite},// timing ISP x win H
	{0x3811,0x08,"0x0100",eReadWrite},// timing ISP x win L
	{0x3812,0x00,"0x0100",eReadWrite},// timing ISP y win H
	{0x3813,0x02,"0x0100",eReadWrite},// timing ISP y win L
	{0x3814,0x31,"0x0100",eReadWrite},// timing X inc
	{0x3815,0x31,"0x0100",eReadWrite},// timing Y inc
	{0x3820,0x04,"0x0100",eReadWrite},// v fast vbin on, flip off, v bin on
	{0x3821,0x1f,"0x0100",eReadWrite},// hsync on, h mirror on, h bin on
	{0x3a04,0x06,"0x0100",eReadWrite},//
	{0x3a05,0x14,"0x0100",eReadWrite},//
	{0x5002,0x00,"0x0100",eReadWrite},// scale off
//	{0x0100,0x01,"0x0100",eReadWrite},// wake up   

	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_twolane_resolution_2592_1944[] =
{
//Capture 2592x1944 22.5fps 24M MCLK 2lane 640Mbps/lane
	{0x0100,0x00,"0x0100",eReadWrite},// software sleep
	{0x3708,0xe2,"0x0100",eReadWrite},// sensor control
	{0x3709,0xc3,"0x0100",eReadWrite},// sensor control
	{0x3801,0x00,"0x0100",eReadWrite},// X start L
	{0x3803,0x00,"0x0100",eReadWrite},// timing Y start L
	{0x3806,0x07,"0x0100",eReadWrite},// timing Y end H
	{0x3807,0xa3,"0x0100",eReadWrite},// timing Y end L
	{0x3808,0x0a,"0x0100",eReadWrite},// X output size H
	{0x3809,0x20,"0x0100",eReadWrite},// X output size L
	{0x380a,0x07,"0x0100",eReadWrite},// Y output size H
	{0x380b,0x98,"0x0100",eReadWrite},// Y output size L
	{0x380c,0x0a,"0x0100",eReadWrite},// HTS H
	{0x380d,0x80,"0x0100",eReadWrite},// HTS L
	{0x380e,0x07,"0x0100",eReadWrite},// VTS H
	{0x380f,0xc0,"0x0100",eReadWrite},// VTS L
	{0x3810,0x00,"0x0100",eReadWrite},// timing ISP x win H
	{0x3811,0x10,"0x0100",eReadWrite},// timing ISP x win L
	{0x3812,0x00,"0x0100",eReadWrite},// timing ISP y win H
	{0x3813,0x06,"0x0100",eReadWrite},// timing ISP y win L
	{0x3814,0x11,"0x0100",eReadWrite},// timing X inc
	{0x3815,0x11,"0x0100",eReadWrite},// timing Y inc
	{0x3820,0x00,"0x0100",eReadWrite},// h bin off
	{0x3821,0x1e,"0x0100",eReadWrite},// hsync on, h mirror on, h bin off
	{0x3a04,0x06,"0x0100",eReadWrite},//
	{0x3a05,0x14,"0x0100",eReadWrite},//
	{0x5002,0x00,"0x0100",eReadWrite},// scale off
//	{0x0100,0x01,"0x0100",eReadWrite},// wake up 

	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};


const IsiRegDescription_t Sensor_g_1296x972P30_twolane_fpschg[] =
{
//	{0x380e, 0x03,"0x0100",eReadWrite},
//	{0x380f, 0xe0,"0x0100",eReadWrite},
	{0x380e, 0x05,"0x0100",eReadWrite},
	{0x380f, 0xd0,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};
const IsiRegDescription_t Sensor_g_1296x972P25_twolane_fpschg[] =
{
//	{0x380e, 0x04,"0x0100",eReadWrite},
//	{0x380f, 0xa6,"0x0100",eReadWrite},
	{0x380e, 0x06,"0x0100",eReadWrite},
	{0x380f, 0xf9,"0x0100",eReadWrite},

	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};
const IsiRegDescription_t Sensor_g_1296x972P20_twolane_fpschg[] =
{
//	{0x380e, 0x05,"0x0100",eReadWrite},
//	{0x380f, 0xd0,"0x0100",eReadWrite},
	{0x380e, 0x08,"0x0100",eReadWrite},
	{0x380f, 0xb8,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};

const IsiRegDescription_t Sensor_g_1296x972P15_twolane_fpschg[] =
{
//	{0x380e, 0x07,"0x0100",eReadWrite},
//	{0x380f, 0xc0,"0x0100",eReadWrite},
	{0x380e, 0x0b,"0x0100",eReadWrite},
	{0x380f, 0xa0,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};
const IsiRegDescription_t Sensor_g_1296x972P10_twolane_fpschg[] =
{
//	{0x380e, 0x0b,"0x0100",eReadWrite},
//	{0x380f, 0xa0,"0x0100",eReadWrite},
	{0x380e, 0x11,"0x0100",eReadWrite},
	{0x380f, 0x70,"0x0100",eReadWrite},

	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};

//22fps
const IsiRegDescription_t Sensor_g_2592x1944P15_twolane_fpschg[] =
{
	{0x380e, 0x0c,"0x0100",eReadWrite},
	{0x380f, 0x00,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};
//10fps
const IsiRegDescription_t Sensor_g_2592x1944P7_twolane_fpschg[] =
{
	{0x380e, 0x18,"0x0100",eReadWrite},
	{0x380f, 0x00,"0x0100",eReadWrite},
	{0x0000 ,0x00,"eTableEnd",eTableEnd}
};



//one lane
const IsiRegDescription_t Sensor_g_aRegDescription_onelane[] =
{

	{0x0000 ,0x00,"eTableEnd",eTableEnd}

};

const IsiRegDescription_t Sensor_g_onelane_resolution_2592_1944[] =
{

	{0x0000, 0x00 ,"eTableEnd",eTableEnd}
};


const IsiRegDescription_t Sensor_g_onelane_resolution_1296_972[] =
{

    {0x0000 ,0x00,"eTableEnd",eTableEnd}
};

