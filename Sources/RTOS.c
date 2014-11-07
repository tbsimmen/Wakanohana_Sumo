/*
 * RTOS.c
 *
 *  Created on: 24.10.2014
 *      Author: tbsimmen
 *
 *       * This module the main tasks of the RTOS.
 */


#include "Platform.h"
#if PL_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED.h"
#include "Application.h"
#include "Event.h"
#include "Keys.h"

static portTASK_FUNCTION(T1, pvParameters) {
  for(;;) {
  }
}


static portTASK_FUNCTION(LEDBLINK, pvParameters) {
  for(;;) {
    LED1_Neg();
    vTaskDelay(1000/portTICK_RATE_MS);
  }
}



static portTASK_FUNCTION(APP_Loop,pvParameters){
	for(;;){
#if PL_HAS_EVENTS
		EVNT_HandleEvent(APP_EventHandler);
#endif
		KEY_Scan();

		 vTaskDelay(100/portTICK_RATE_MS);
	}
}


void RTOS_Run(void) {
  FRTOS1_vTaskStartScheduler();
}

void RTOS_Init(void) {
  /*! \todo Add tasks here */

	 if (FRTOS1_xTaskCreate(APP_Loop, (signed portCHAR *)"App_Loop", configMINIMAL_STACK_SIZE, NULL,1, NULL) != pdPASS) {
		    for(;;){} /* error */
		  }

	  if (FRTOS1_xTaskCreate(LEDBLINK, (signed portCHAR *)"LEDBLINK", configMINIMAL_STACK_SIZE, NULL,0, NULL) != pdPASS) {
	    for(;;){} /* error */
	  }

  if (FRTOS1_xTaskCreate(T1, (signed portCHAR *)"T1", configMINIMAL_STACK_SIZE, NULL,0, NULL) != pdPASS) {
    for(;;){} /* error */
  }

int i = 0;


}

void RTOS_Deinit(void) {
}

#endif /* PL_HAS_RTOS */
