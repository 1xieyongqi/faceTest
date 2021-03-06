//IMX291_tables.c
/*****************************************************************************/
/*!
 *  \file        IMX291_tables.c \n
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

#if( IMX291_DRIVER_USAGE == USE_CAM_DRV_EN )
*/


#include <ebase/types.h>
#include <ebase/trace.h>
#include <ebase/builtins.h>

#include <common/return_codes.h>

#include "isi.h"
#include "isi_iss.h"
#include "isi_priv.h"
#include "IMX291_MIPI_priv.h"


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

{0x3000 , 0x01 , "0x0100" , eReadWrite},
{0x3002 , 0x01 , "0x0100" , eReadWrite},
{0x3005 , 0x01 , "0x0100" , eReadWrite}, //10bit  0x00  , 12bit 0x01
{0x3009 , 0x11 , "0x0100" , eReadWrite},
{0x3007 , 0x01 , "0x0100" , eReadWrite},
{0x300F , 0x00 , "0x0100" , eReadWrite},
{0x3010 , 0x21 , "0x0100" , eReadWrite},
{0x3012 , 0x64 , "0x0100" , eReadWrite},
{0x3016 , 0x09 , "0x0100" , eReadWrite},
{0x301C , 0x98 , "0x0100" , eReadWrite},
{0x301D , 0x08 , "0x0100" , eReadWrite},
{0x305C , 0x18 , "0x0100" , eReadWrite},
{0x305D , 0x03 , "0x0100" , eReadWrite},
{0x305E , 0x20 , "0x0100" , eReadWrite},
{0x305F , 0x01 , "0x0100" , eReadWrite},
{0x3070 , 0x02 , "0x0100" , eReadWrite},
{0x3071 , 0x11 , "0x0100" , eReadWrite},
{0x309B , 0x10 , "0x0100" , eReadWrite},
{0x309C , 0x22 , "0x0100" , eReadWrite},
{0x30A2 , 0x02 , "0x0100" , eReadWrite},
{0x30A6 , 0x20 , "0x0100" , eReadWrite},
{0x30A8 , 0x20 , "0x0100" , eReadWrite},
{0x30AA , 0x20 , "0x0100" , eReadWrite},
{0x30AC , 0x20 , "0x0100" , eReadWrite},
{0x30B0 , 0x43 , "0x0100" , eReadWrite},
{0x3119 , 0x9E , "0x0100" , eReadWrite},
{0x311C , 0x1E , "0x0100" , eReadWrite},
{0x311E , 0x08 , "0x0100" , eReadWrite},
{0x3128 , 0x05 , "0x0100" , eReadWrite},
{0x3129 , 0x00 , "0x0100" , eReadWrite},  //10bit 0x1D  , 12bit 0x00 
{0x313D , 0x83 , "0x0100" , eReadWrite},
{0x3150 , 0x03 , "0x0100" , eReadWrite},
{0x315E , 0x1A , "0x0100" , eReadWrite},
{0x3164 , 0x1A , "0x0100" , eReadWrite},
{0x317C , 0x00 , "0x0100" , eReadWrite},  //10bit 0x12  , 12bit 0x00
{0x317E , 0x00 , "0x0100" , eReadWrite},
{0x31EC , 0x0E , "0x0100" , eReadWrite},   //10bit 0x37  , 12bit 0x0E
{0x32B8 , 0x50 , "0x0100" , eReadWrite},
{0x32B9 , 0x10 , "0x0100" , eReadWrite},
{0x32BA , 0x00 , "0x0100" , eReadWrite},
{0x32BB , 0x04 , "0x0100" , eReadWrite},
{0x32C8 , 0x50 , "0x0100" , eReadWrite},
{0x32C9 , 0x10 , "0x0100" , eReadWrite},
{0x32CA , 0x00 , "0x0100" , eReadWrite},
{0x32CB , 0x04 , "0x0100" , eReadWrite},
{0x332C , 0xD3 , "0x0100" , eReadWrite},
{0x332D , 0x10 , "0x0100" , eReadWrite},
{0x332E , 0x0D , "0x0100" , eReadWrite},
{0x3358 , 0x06 , "0x0100" , eReadWrite},
{0x3359 , 0xE1 , "0x0100" , eReadWrite},
{0x335A , 0x11 , "0x0100" , eReadWrite},
{0x3360 , 0x1E , "0x0100" , eReadWrite},
{0x3361 , 0x61 , "0x0100" , eReadWrite},
{0x3362 , 0x10 , "0x0100" , eReadWrite},
{0x33B0 , 0x50 , "0x0100" , eReadWrite},
{0x33B2 , 0x1A , "0x0100" , eReadWrite},
{0x33B3 , 0x04 , "0x0100" , eReadWrite},
{0x3405 , 0x00 , "0x0100" , eReadWrite},
{0x3407 , 0x01 , "0x0100" , eReadWrite},
{0x3418 , 0x49 , "0x0100" , eReadWrite},
{0x3419 , 0x04 , "0x0100" , eReadWrite},
{0x3441 , 0x0A , "0x0100" , eReadWrite},
{0x3442 , 0x0A , "0x0100" , eReadWrite},
{0x3443 , 0x01 , "0x0100" , eReadWrite},
{0x3444 , 0x20 , "0x0100" , eReadWrite},
{0x3445 , 0x25 , "0x0100" , eReadWrite},
{0x3446 , 0x77 , "0x0100" , eReadWrite},
{0x3448 , 0x67 , "0x0100" , eReadWrite},
{0x344A , 0x47 , "0x0100" , eReadWrite},
{0x344C , 0x37 , "0x0100" , eReadWrite},
{0x344E , 0x3F , "0x0100" , eReadWrite},
{0x3450 , 0xFF , "0x0100" , eReadWrite},
{0x3452 , 0x3F , "0x0100" , eReadWrite},
{0x3454 , 0x37 , "0x0100" , eReadWrite},
{0x3480 , 0x49 , "0x0100" , eReadWrite},
//{0x3000 , 0x00 , "0x0100" , eReadWrite},
{0x3002 , 0x00 , "0x0100" , eReadWrite},



{0x0000, 0x00, "eReadWrite",eTableEnd}



};


const IsiRegDescription_t Sensor_g_1920x1080_twolane[] =
{

{0x3000 , 0x01 , "0x0100" , eReadWrite},
{0x3002 , 0x01 , "0x0100" , eReadWrite},
{0x3005 , 0x01 , "0x0100" , eReadWrite}, //10bit  0x00  , 12bit 0x01
{0x3007 , 0x01 , "0x0100" , eReadWrite},
{0x3009 , 0x11 , "0x0100" , eReadWrite},
{0x300F , 0x00 , "0x0100" , eReadWrite},
{0x3010 , 0x21 , "0x0100" , eReadWrite},
{0x3012 , 0x64 , "0x0100" , eReadWrite},
{0x3016 , 0x09 , "0x0100" , eReadWrite},
{0x301C , 0x98 , "0x0100" , eReadWrite},
{0x301D , 0x08 , "0x0100" , eReadWrite},
{0x305C , 0x18 , "0x0100" , eReadWrite},
{0x305D , 0x03 , "0x0100" , eReadWrite},
{0x305E , 0x20 , "0x0100" , eReadWrite},
{0x305F , 0x01 , "0x0100" , eReadWrite},
{0x3070 , 0x02 , "0x0100" , eReadWrite},
{0x3071 , 0x11 , "0x0100" , eReadWrite},
{0x309B , 0x10 , "0x0100" , eReadWrite},
{0x309C , 0x22 , "0x0100" , eReadWrite},
{0x30A2 , 0x02 , "0x0100" , eReadWrite},
{0x30A6 , 0x20 , "0x0100" , eReadWrite},
{0x30A8 , 0x20 , "0x0100" , eReadWrite},
{0x30AA , 0x20 , "0x0100" , eReadWrite},
{0x30AC , 0x20 , "0x0100" , eReadWrite},
{0x30B0 , 0x43 , "0x0100" , eReadWrite},
{0x3119 , 0x9E , "0x0100" , eReadWrite},
{0x311C , 0x1E , "0x0100" , eReadWrite},
{0x311E , 0x08 , "0x0100" , eReadWrite},
{0x3128 , 0x05 , "0x0100" , eReadWrite},
{0x3129 , 0x00 , "0x0100" , eReadWrite},  //10bit 0x1D  , 12bit 0x00 
{0x313D , 0x83 , "0x0100" , eReadWrite},
{0x3150 , 0x03 , "0x0100" , eReadWrite},
{0x315E , 0x1A , "0x0100" , eReadWrite},
{0x3164 , 0x1A , "0x0100" , eReadWrite},
{0x317C , 0x00 , "0x0100" , eReadWrite},  //10bit 0x12  , 12bit 0x00
{0x317E , 0x00 , "0x0100" , eReadWrite},
{0x31EC , 0x0E , "0x0100" , eReadWrite},   //10bit 0x37  , 12bit 0x0E
{0x32B8 , 0x50 , "0x0100" , eReadWrite},
{0x32B9 , 0x10 , "0x0100" , eReadWrite},
{0x32BA , 0x00 , "0x0100" , eReadWrite},
{0x32BB , 0x04 , "0x0100" , eReadWrite},
{0x32C8 , 0x50 , "0x0100" , eReadWrite},
{0x32C9 , 0x10 , "0x0100" , eReadWrite},
{0x32CA , 0x00 , "0x0100" , eReadWrite},
{0x32CB , 0x04 , "0x0100" , eReadWrite},
{0x332C , 0xD3 , "0x0100" , eReadWrite},
{0x332D , 0x10 , "0x0100" , eReadWrite},
{0x332E , 0x0D , "0x0100" , eReadWrite},
{0x3358 , 0x06 , "0x0100" , eReadWrite},
{0x3359 , 0xE1 , "0x0100" , eReadWrite},
{0x335A , 0x11 , "0x0100" , eReadWrite},
{0x3360 , 0x1E , "0x0100" , eReadWrite},
{0x3361 , 0x61 , "0x0100" , eReadWrite},
{0x3362 , 0x10 , "0x0100" , eReadWrite},
{0x33B0 , 0x50 , "0x0100" , eReadWrite},
{0x33B2 , 0x1A , "0x0100" , eReadWrite},
{0x33B3 , 0x04 , "0x0100" , eReadWrite},
{0x3405 , 0x00 , "0x0100" , eReadWrite},
{0x3407 , 0x01 , "0x0100" , eReadWrite},
{0x3418 , 0x49 , "0x0100" , eReadWrite},
{0x3419 , 0x04 , "0x0100" , eReadWrite},
{0x3441 , 0x0A , "0x0100" , eReadWrite},
{0x3442 , 0x0A , "0x0100" , eReadWrite},
{0x3443 , 0x01 , "0x0100" , eReadWrite},
{0x3444 , 0x20 , "0x0100" , eReadWrite},
{0x3445 , 0x25 , "0x0100" , eReadWrite},
{0x3446 , 0x77 , "0x0100" , eReadWrite},
{0x3448 , 0x67 , "0x0100" , eReadWrite},
{0x344A , 0x47 , "0x0100" , eReadWrite},
{0x344C , 0x37 , "0x0100" , eReadWrite},
{0x344E , 0x3F , "0x0100" , eReadWrite},
{0x3450 , 0xFF , "0x0100" , eReadWrite},
{0x3452 , 0x3F , "0x0100" , eReadWrite},
{0x3454 , 0x37 , "0x0100" , eReadWrite},
{0x3480 , 0x49 , "0x0100" , eReadWrite},
//{0x3000 , 0x00 , "0x0100" , eReadWrite},
{0x3002 , 0x00 , "0x0100" , eReadWrite},



{0x0000, 0x00, "eReadWrite",eTableEnd}



};
const IsiRegDescription_t Sensor_g_1920x1080P50_twolane_fpschg[] =
{
    {0x3018,0x46, "0x0100", eReadWrite}, 
    {0x3019,0x05, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};

const IsiRegDescription_t Sensor_g_1920x1080P30_twolane_fpschg[] =
{
    {0x3018,0xca, "0x0100", eReadWrite}, 
    {0x3019,0x08, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};

const IsiRegDescription_t Sensor_g_1920x1080P25_twolane_fpschg[] =
{
    {0x3018,0x8c, "0x0100", eReadWrite}, 
    {0x3019,0x0a, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};

const IsiRegDescription_t Sensor_g_1920x1080P15_twolane_fpschg[] =
{
    {0x3018,0x94, "0x0100", eReadWrite}, 
    {0x3019,0x11, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};


//four lane
const IsiRegDescription_t Sensor_g_aRegDescription_fourlane[] =
{

{0x3000, 0x01, "0x0100" , eReadWrite},
{0x3002, 0x01, "0x0100" , eReadWrite},
{0x3005, 0x01, "0x0100" , eReadWrite},   //10bit : 0x00   12bit :0x01
{0x3007, 0x01, "0x0100" , eReadWrite},
{0x3009, 0x11, "0x0100" , eReadWrite},
{0x3012, 0x64, "0x0100" , eReadWrite},
{0x300F, 0x00, "0x0100" , eReadWrite},
{0x3010, 0x21, "0x0100" , eReadWrite},
{0x3012, 0x64, "0x0100" , eReadWrite},
{0x3014, 0x00, "0x0100" , eReadWrite}, //Gain setting
{0x3016, 0x09, "0x0100" , eReadWrite},
{0x3018, 0x65, "0x0100" , eReadWrite}, //VMAX
{0x3019, 0x04, "0x0100" , eReadWrite}, //
{0x301A, 0x00, "0x0100" , eReadWrite}, //
{0x301C, 0x98, "0x0100" , eReadWrite}, //HMAX
{0x301D, 0x08, "0x0100" , eReadWrite}, //
{0x3020, 0x00, "0x0100" , eReadWrite}, //SHS1 storage time adjustment
{0x3021, 0x00, "0x0100" , eReadWrite}, //
{0x3022, 0x00, "0x0100" , eReadWrite}, //
{0x305C, 0x18, "0x0100" , eReadWrite},
{0x305D, 0x03, "0x0100" , eReadWrite}, 
{0x305E, 0x20, "0x0100" , eReadWrite},
{0x305F, 0x01, "0x0100" , eReadWrite},
{0x3070, 0x02, "0x0100" , eReadWrite},
{0x3071, 0x11, "0x0100" , eReadWrite},
{0x30A6, 0x20, "0x0100" , eReadWrite},
{0x30A8, 0x20, "0x0100" , eReadWrite},
{0x30AA, 0x20, "0x0100" , eReadWrite},
{0x30AC, 0x20, "0x0100" , eReadWrite},
{0x310B, 0x00, "0x0100" , eReadWrite},
{0x3119, 0x9E, "0x0100" , eReadWrite},
{0x311E, 0x08, "0x0100" , eReadWrite},
{0x3128, 0x05, "0x0100" , eReadWrite},
{0x3129, 0x00, "0x0100" , eReadWrite},  //10bit 0x1D	, 12bit 0x00 
{0x3134, 0x0F, "0x0100" , eReadWrite},
{0x313B, 0x50, "0x0100" , eReadWrite},
{0x313D, 0x83, "0x0100" , eReadWrite},
{0x315E, 0x1A, "0x0100" , eReadWrite},
{0x3164, 0x1A, "0x0100" , eReadWrite},
{0x317C, 0x00, "0x0100" , eReadWrite},  //10bit 0x12  , 12bit 0x00
{0x317F, 0x00, "0x0100" , eReadWrite},
{0x31EC, 0x0E, "0x0100" , eReadWrite},   //10bit 0x37  , 12bit 0x0E
{0x32B8, 0x50, "0x0100" , eReadWrite},
{0x32B9, 0x10, "0x0100" , eReadWrite},
{0x32BA, 0x00, "0x0100" , eReadWrite},
{0x32BB, 0x04, "0x0100" , eReadWrite},
{0x32C8, 0x50, "0x0100" , eReadWrite},
{0x32C9, 0x10, "0x0100" , eReadWrite},
{0x32CA, 0x00, "0x0100" , eReadWrite},
{0x32CB, 0x04, "0x0100" , eReadWrite},
{0x332C, 0xD3, "0x0100" , eReadWrite},
{0x332D, 0x10, "0x0100" , eReadWrite},
{0x332E, 0x0D, "0x0100" , eReadWrite},
{0x3358, 0x06, "0x0100" , eReadWrite},
{0x3359, 0xE1, "0x0100" , eReadWrite},
{0x335A, 0x11, "0x0100" , eReadWrite},
{0x3360, 0x1E, "0x0100" , eReadWrite},
{0x3361, 0x61, "0x0100" , eReadWrite},
{0x3362, 0x10, "0x0100" , eReadWrite},
{0x33B0, 0x08, "0x0100" , eReadWrite},
{0x33B1, 0x30, "0x0100" , eReadWrite},
{0x33B3, 0x04, "0x0100" , eReadWrite},
{0x3405, 0x10, "0x0100" , eReadWrite},
{0x3441, 0x0A, "0x0100" , eReadWrite},
{0x3442, 0x0A, "0x0100" , eReadWrite},
{0X3444, 0x20, "0x0100" , eReadWrite},
{0x3445, 0x25, "0x0100" , eReadWrite},
{0x3446, 0x57, "0x0100" , eReadWrite},
{0x3448, 0x37, "0x0100" , eReadWrite},
{0x344A, 0x1F, "0x0100" , eReadWrite},
{0x344C, 0x1F, "0x0100" , eReadWrite},
{0x344E, 0x1F, "0x0100" , eReadWrite},
{0x3450, 0x77, "0x0100" , eReadWrite},
{0x3452, 0x1F, "0x0100" , eReadWrite},
{0x3454, 0x17, "0x0100" , eReadWrite},
{0x3480, 0x49, "0x0100" , eReadWrite},
//{0x3000, 0x00, "0x0100" , eReadWrite},
{0x3002, 0x00, "0x0100" , eReadWrite},


{0x0000, 0x00, "eReadWrite",eTableEnd}

};


const IsiRegDescription_t Sensor_g_1920x1080_fourlane[] =
{

{0x3000, 0x01, "0x0100" , eReadWrite},
{0x3002, 0x01, "0x0100" , eReadWrite},
{0x3005, 0x01, "0x0100" , eReadWrite},   //10bit : 0x00   12bit :0x01
{0x3007, 0x01, "0x0100" , eReadWrite},
{0x3009, 0x11, "0x0100" , eReadWrite},
{0x3012, 0x64, "0x0100" , eReadWrite},
{0x300F, 0x00, "0x0100" , eReadWrite},
{0x3010, 0x21, "0x0100" , eReadWrite},
{0x3012, 0x64, "0x0100" , eReadWrite},
{0x3014, 0x00, "0x0100" , eReadWrite}, //Gain setting
{0x3016, 0x09, "0x0100" , eReadWrite},
{0x3018, 0x65, "0x0100" , eReadWrite}, //VMAX
{0x3019, 0x04, "0x0100" , eReadWrite}, //
{0x301A, 0x00, "0x0100" , eReadWrite}, //
{0x301C, 0x98, "0x0100" , eReadWrite}, //HMAX
{0x301D, 0x08, "0x0100" , eReadWrite}, //
{0x3020, 0x00, "0x0100" , eReadWrite}, //SHS1 storage time adjustment
{0x3021, 0x00, "0x0100" , eReadWrite}, //
{0x3022, 0x00, "0x0100" , eReadWrite}, //
{0x305C, 0x18, "0x0100" , eReadWrite},
{0x305D, 0x03, "0x0100" , eReadWrite}, 
{0x305E, 0x20, "0x0100" , eReadWrite},
{0x305F, 0x01, "0x0100" , eReadWrite},
{0x3070, 0x02, "0x0100" , eReadWrite},
{0x3071, 0x11, "0x0100" , eReadWrite},
{0x30A6, 0x20, "0x0100" , eReadWrite},
{0x30A8, 0x20, "0x0100" , eReadWrite},
{0x30AA, 0x20, "0x0100" , eReadWrite},
{0x30AC, 0x20, "0x0100" , eReadWrite},
{0x310B, 0x00, "0x0100" , eReadWrite},
{0x3119, 0x9E, "0x0100" , eReadWrite},
{0x311E, 0x08, "0x0100" , eReadWrite},
{0x3128, 0x05, "0x0100" , eReadWrite},
{0x3129, 0x00, "0x0100" , eReadWrite},  //10bit 0x1D	, 12bit 0x00 
{0x3134, 0x0F, "0x0100" , eReadWrite},
{0x313B, 0x50, "0x0100" , eReadWrite},
{0x313D, 0x83, "0x0100" , eReadWrite},
{0x315E, 0x1A, "0x0100" , eReadWrite},
{0x3164, 0x1A, "0x0100" , eReadWrite},
{0x317C, 0x00, "0x0100" , eReadWrite},  //10bit 0x12  , 12bit 0x00
{0x317F, 0x00, "0x0100" , eReadWrite},
{0x31EC, 0x0E, "0x0100" , eReadWrite},   //10bit 0x37  , 12bit 0x0E
{0x32B8, 0x50, "0x0100" , eReadWrite},
{0x32B9, 0x10, "0x0100" , eReadWrite},
{0x32BA, 0x00, "0x0100" , eReadWrite},
{0x32BB, 0x04, "0x0100" , eReadWrite},
{0x32C8, 0x50, "0x0100" , eReadWrite},
{0x32C9, 0x10, "0x0100" , eReadWrite},
{0x32CA, 0x00, "0x0100" , eReadWrite},
{0x32CB, 0x04, "0x0100" , eReadWrite},
{0x332C, 0xD3, "0x0100" , eReadWrite},
{0x332D, 0x10, "0x0100" , eReadWrite},
{0x332E, 0x0D, "0x0100" , eReadWrite},
{0x3358, 0x06, "0x0100" , eReadWrite},
{0x3359, 0xE1, "0x0100" , eReadWrite},
{0x335A, 0x11, "0x0100" , eReadWrite},
{0x3360, 0x1E, "0x0100" , eReadWrite},
{0x3361, 0x61, "0x0100" , eReadWrite},
{0x3362, 0x10, "0x0100" , eReadWrite},
{0x33B0, 0x08, "0x0100" , eReadWrite},
{0x33B1, 0x30, "0x0100" , eReadWrite},
{0x33B3, 0x04, "0x0100" , eReadWrite},
{0x3405, 0x10, "0x0100" , eReadWrite},
{0x3441, 0x0A, "0x0100" , eReadWrite},
{0x3442, 0x0A, "0x0100" , eReadWrite},
{0X3444, 0x20, "0x0100" , eReadWrite},
{0x3445, 0x25, "0x0100" , eReadWrite},
{0x3446, 0x57, "0x0100" , eReadWrite},
{0x3448, 0x37, "0x0100" , eReadWrite},
{0x344A, 0x1F, "0x0100" , eReadWrite},
{0x344C, 0x1F, "0x0100" , eReadWrite},
{0x344E, 0x1F, "0x0100" , eReadWrite},
{0x3450, 0x77, "0x0100" , eReadWrite},
{0x3452, 0x1F, "0x0100" , eReadWrite},
{0x3454, 0x17, "0x0100" , eReadWrite},
{0x3480, 0x49, "0x0100" , eReadWrite},
//{0x3000, 0x00, "0x0100" , eReadWrite},
{0x3002, 0x00, "0x0100" , eReadWrite},


{0x0000, 0x00, "eReadWrite",eTableEnd}

};

const IsiRegDescription_t Sensor_g_1920x1080P60_fourlane_fpschg[] =
{
    {0x3018,0x65, "0x0100", eReadWrite},
    {0x3019,0x04, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};
const IsiRegDescription_t Sensor_g_1920x1080P50_fourlane_fpschg[] =
{
    {0x3018,0x46, "0x0100", eReadWrite}, 
    {0x3019,0x05, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};
const IsiRegDescription_t Sensor_g_1920x1080P30_fourlane_fpschg[] =
{
    {0x3018,0xca, "0x0100", eReadWrite}, 
    {0x3019,0x08, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};

const IsiRegDescription_t Sensor_g_1920x1080P25_fourlane_fpschg[] =
{
    {0x3018,0x8c, "0x0100", eReadWrite}, 
    {0x3019,0x0a, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};
const IsiRegDescription_t Sensor_g_1920x1080P20_fourlane_fpschg[] =
{
    {0x3018,0x2f, "0x0100", eReadWrite}, 
    {0x3019,0x0d, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};

const IsiRegDescription_t Sensor_g_1920x1080P15_fourlane_fpschg[] =
{
    {0x3018,0x94, "0x0100", eReadWrite}, 
    {0x3019,0x11, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};

const IsiRegDescription_t Sensor_g_1920x1080P10_fourlane_fpschg[] =
{
    {0x3018,0x5e, "0x0100", eReadWrite}, 
    {0x3019,0x1a, "0x0100", eReadWrite},
	{0x0000, 0x00, "eReadWrite",eTableEnd}
	
};







