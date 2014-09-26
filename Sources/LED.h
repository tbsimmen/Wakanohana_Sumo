/*
 * LED.h
 *
 *  Created on: 26.09.2014
 *      Author: tbsimmen
 *
 *  \brief LED driver implementation.
 *  \author M. Simmen marc.simmen@hslu.ch
 *
 *  This Module implements a generic LED driver for up to 5 LED's.
 *  It is using macros for maximum flexibility with minimal code overhead.
 *
 */



#ifndef LED_H_
#define LED_H_

#include "Platform.h"


#if PL_NOF_LEDS >=1
#include "MyBlueLed.h"
#define LED1_On() 		MyBlueLed_ClrVal()			/* Turn LED 1 on */
#define LED1_Off() 		MyBlueLed_SetVal() 			/* Turn LED 1 off */
#define LED1_Neg()  	MyBlueLed_NegVal() 		    /*!< Toggle LED 1 */
#define LED1_Get()  	MyBlueLed_GetVal()		    /*!< Return TRUE if LED is on, FALSE otherwise */
#define LED1_Put(val) 	MyBlueLed_PutVal(val)			/*!< Turn LED on or off */
#define LED1_Init()   	/* do nothing */		    /*!< Initialize LED */
#define LED1_Deinit()   /* do nothing */		    /*!< De-Initialize LED */
#else
#define LED1_On()     /* do nothing */			    /*!< Turn LED 1 on */
#define LED1_Off()    /* do nothing */			    /*!< Turn LED 1 off */
#define LED1_Neg()    /* do nothing */          	/*!< Toggle LED 1 */
#define LED1_Get()  0 /* do nothing */		    	/*!< Return TRUE if LED is on, FALSE otherwise */
#define LED1_Put(val) /* do nothing */		    	/*!< Turn LED 1 on or off */
#define LED1_Init()   /* do nothing */		    	/*!< Initialize LED 1 */
#define LED1_Deinit() /* do nothing */		    	/*!< De-Initialize LED 1 */
#endif

#if PL_NOF_LEDS >= 2
  #include "MyGreenLed.h"
  #define LED2_On()     MyGreenLed_ClrVal()		    /*!< Turn LED 1 on */
  #define LED2_Off()    MyGreenLed_SetVal()		    /*!< Turn LED 1 off */
  #define LED2_Neg()    MyGreenLed_NegVal()		    /*!< Toggle LED 1 */
  #define LED2_Get()    MyGreenLed_GetVal()		    /*!< Return TRUE if LED is on, FALSE otherwise */
  #define LED2_Put(val) MyGreenLed_PutVal(val)		    /*!< Turn LED on or off */
  #define LED2_Init()   /* do nothing */		    /*!< Initialize LED */
  #define LED2_Deinit() /* do nothing */		    /*!< De-Initialize LED */
#else
  #define LED2_On()     /* do nothing */		    /*!< Turn LED 2 on */
  #define LED2_Off()    /* do nothing */		    /*!< Turn LED 2 off */
  #define LED2_Neg()    /* do nothing */		    /*!< Toggle LED 2 */
  #define LED2_Get()  0 /* do nothing */		    /*!< Return TRUE if LED is on, FALSE otherwise */
  #define LED2_Put(val) /* do nothing */		    /*!< Turn LED 2 on or off */
  #define LED2_Init()   /* do nothing */		    /*!< Initialize LED 2 */
  #define LED2_Deinit() /* do nothing */		    /*!< De-Initialize LED 2 */
#endif

#if PL_NOF_LEDS >= 3
  #include "MyRedLed.h"
  #define LED3_On()     MyRedLed_ClrVal()		    /*!< Turn LED 1 on */
  #define LED3_Off()    MyRedLed_SetVal()		    /*!< Turn LED 1 off */
  #define LED3_Neg()    MyRedLed_NegVal()		    /*!< Toggle LED 1 */
  #define LED3_Get()    MyRedLed_GetVal()		    /*!< Return TRUE if LED is on, FALSE otherwise */
  #define LED3_Put(val) MyRedLed_PutVal(val)		    /*!< Turn LED on or off */
  #define LED3_Init()   /* do nothing */		    /*!< Initialize LED */
  #define LED3_Deinit() /* do nothing */		    /*!< De-Initialize LED */
#else
  #define LED3_On()     /* do nothing */		    /*!< Turn LED 3 on */
  #define LED3_Off()    /* do nothing */		    /*!< Turn LED 3 off */
  #define LED3_Neg()    /* do nothing */		    /*!< Toggle LED 3 */
  #define LED3_Get()  0 /* do nothing */		    /*!< Return TRUE if LED is on, FALSE otherwise */
  #define LED3_Put(val) /* do nothing */		    /*!< Turn LED 3 on or off */
  #define LED3_Init()   /* do nothing */		    /*!< Initialize LED 3 */
  #define LED3_Deinit() /* do nothing */		    /*!< De-Initialize LED 3 */
#endif

/*!
 * \brief LED test routine.
 * This routine tests if:
 * - we can turn the LEDs properly on and off
 * - if we can negate them
 * - if we can set an LED value
 * - if we can get the LED value
 * If the test fails, the program will hanging in an endless loop
 */
void LED_Test(void);

/*!
 * \brief LED Driver Intialization.
 */
void LED_Init(void);

/*!
 * \brief LED Driver De-Initialization.
 */
void LED_Deinit(void);

#endif /* LED_H_ */
