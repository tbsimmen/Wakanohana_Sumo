/*
 * Application.c
 *
 *  Created on: 26.09.2014
 *      Author: tbsimmen
 *
 * This module is the main application module.
 * From here the application runs and performs all tasks.
 */

#include "Platform.h"
#include "Application.h"
#if PL_HAS_LED
  #include "LED.h"
#endif


void APP_Start(void) {
  PL_Init(); /* platform initialization */
  for(;;) {
    LED1_Neg();
    WAIT1_Waitms(300);
    LED2_Neg();
    WAIT1_Waitms(300);
    LED3_Neg();
    WAIT1_Waitms(300);
  }
}



