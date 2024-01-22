/*
 * _7segment.h
 *
 * Created: 12/10/2023 9:27:58 PM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef _7SEGMENT_H_
#define _7SEGMENT_H_
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Timer/timer.h"
//									   {0    , 1   , 2  , 3   , 4   , 5   , 6   , 7   , 8    , 9  }
static unsigned char _7SEG_COM_CAT[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
static unsigned char _7SEG_COM_AN[]	 = {0xC0, 0x79, 0x24, 0x30, 0x19 , 0x12, 0x02,0xF8, 0x00, 0x10};





#endif /* 7SEGMENT_H_ */