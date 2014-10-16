/*!
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
#include "WAIT1.h"

#if PL_HAS_LED
  #include "LED.h"
#endif

#if PL_HAS_EVENTS
	#include "Event.h"
#endif

#if PL_HAS_KEYS
	#include "Keys.h"
#endif


void APP_EventHandler(EVNT_Handle event){
	switch(event){
		case EVNT_INIT:
				LED1_On();
				WAIT1_Waitms(100);
				LED1_Off();
				WAIT1_Waitms(100);
				LED2_On();
				WAIT1_Waitms(100);
				LED2_Off();
				WAIT1_Waitms(100);
				LED3_On();
				WAIT1_Waitms(100);
				LED3_Off();
				break;
		case EVNT_BLINK_LED:
			LED2_Neg();
			EVNT_ClearEvent(EVNT_BLINK_LED);
			break;
		case EVNT_SW1_PRESSED:
			if(LED3_Get()){
				LED3_On();
			}else{
				LED3_Off();
			}
			EVNT_ClearEvent(EVNT_SW1_PRESSED);
			break;
		default:
			break; /*Nothing*/
		}
}


static void APP_Loop(void){
	for(;;){
#if PL_HAS_EVENTS
		EVNT_HandleEvent(APP_EventHandler);
#endif
		KEY_Scan();

		WAIT1_Waitms(100);
	}
}

/*Run this Code on board startup*/
void APP_Start(void) {
  PL_Init(); /* platform initialization */
  EVNT_SetEvent(EVNT_INIT); /* set initial Event*/
  APP_Loop();

#if 0
  for(;;){
#if PL_HAS_MEALY
	  MEALY_Step();
#else
	 /*LED1_On();
	     WAIT1_Waitms(300);
	     LED1_Off();
	     LED2_On();
	     WAIT1_Waitms(300);
	     LED2_Off();
	     LED3_On();
	     WAIT1_Waitms(300);
	     LED3_Off();*/
#endif
  }
#endif
  PL_Deinit(); /* Just in case we leave the main application loop*/
  }









