/*
 * Platform.h
 *
 *  Created on: 25.09.2014
 *      Author: tbsimmen
 *
 * \brief Platform implementation module.
 * \author M. Simmen, marc.simmen@hslu.ch
 *
 * Here the platform gets initialized, an all the platform dependent macros get defined.
 */

#include "Platform.h"
#if PL_HAS_LED
	#include "LED.h"
#endif


void PL_Init(void){
#if PL_HAS_LED
	LED_Init();
#endif
}

void PL_Deinit(void){
#if PL_HAS_LED
	LED_Deinit();
#endif
}
