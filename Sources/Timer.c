/**
 * \file
 * \brief Timer driver
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements the driver for all our timers.
  */

#include "Platform.h"
#if PL_HAS_TIMER
	#include "Timer.h"
	#if PL_HAS_LED
		#include "LED.h"
	#endif
	#if PL_HAS_EVENTS
		#include "Event.h"
	#endif


void TMR_OnInterrupt(void) {
  /* this one gets called from an interrupt!!!! */
  static int cntr=0;

  cntr++;
  if (cntr==(1000/TMR_TICK_MS)) {
    EVNT_SetEvent(EVNT_BLINK_LED);
    //LED1_Neg();
    cntr = 0;
  }
}

void TMR_Init(void) {
  /* nothing needed right now */
}

void TMR_Deinit(void) {
  /* nothing needed right now */
}

#endif /*PL_HAS_TIMER*/
