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
#if PL_HAS_MEALY
  #include "Mealy.h"
#endif
#if PL_HAS_KEYS
  #include "Keys.h"
#endif
#if PL_HAS_SHELL
  #include "Shell.h"
#endif
#if PL_HAS_BUZZER
  #include "Buzzer.h"
#endif
#if PL_HAS_RTOS
  #include "RTOS.h"
  #include "FRTOS1.h"
#endif


void APP_EventHandler(EVNT_Handle event){
	switch(event){
		case EVNT_INIT:
				LED1_On();
				WAIT1_Waitms(100);
				LED1_Off();
				LED2_On();
				WAIT1_Waitms(100);
				LED2_Off();
				LED3_On();
				WAIT1_Waitms(100);
				LED3_Off();
				break;
		case EVNT_BLINK_LED:
			LED2_Neg(); //GREEN
			break;
		case EVNT_SW1_PRESSED:
			if(LED3_Get()){ //RED
				LED3_On();
				CLS1_SendStr("LED3 is On!\r\n", CLS1_GetStdio()->stdOut);
			}else{
				LED3_Off();
				CLS1_SendStr("LED3 is Off!\r\n",CLS1_GetStdio()->stdOut);
			}
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
  EVNT_Init();
  EVNT_SetEvent(EVNT_INIT); /* set initial Event*/

  RTOS_Init();
  SHELL_Init();

  RTOS_Run();
//APP_Loop();

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
  SHELL_Deinit();
  PL_Deinit(); /* Just in case we leave the main application loop*/

  }









