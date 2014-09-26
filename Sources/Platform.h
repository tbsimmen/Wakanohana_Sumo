/*
 * Platform.h
 *
 *  Created on: 25.09.2014
 *      Author: tbsimmen
 *
 *   \brief Platform implementation module.
 * 	 \author M. Simmen, marc.simmen@hslu.ch
 *
 *
 * Here the platform gets initialized, an all the platform dependent macros get defined.
 */


#ifndef PLATFORM_H_
#define PLATFORM_H_


#include "PE_Types.h" /* for common Processor Expert types used throughout the project, e.g. 'bool' */
#include "PE_Error.h" /* global error constants */
#include <stddef.h>   /* for NULL */


/* There can be two platforms: FRDM or ROBOT:*/
#define PL_IS_FRDM 1// (defined(PL_BOARD_IS_FRDM)) 		/*!< Macro is defined through compiler option for the FRDM board */
#define PL_IS_ROBO 0//(defined(PL_BOARD_IS_ROBO))   	/*!< Macro is defined through compiler option for the Robot board */ /*<- sog. 'Line Continuation')*/

#define PL_HAS_LED  (1)								/*!< Set to 1 to enable LED support, 0 otherwise */


#if PL_IS_FRDM
  #define PL_NOF_LEDS       (3) 					/*!< FRDM board has up to 3 LEDs (RGB) */
#elif PL_IS_ROBO
  #define PL_NOF_LEDS       (2)   					/*!< We have up to 2 LED's on the robo board */
#else
/*#error: "unknown configuration?"*/
#endif


/*!
 * \brief Platform initialization
 */
void PL_Init(void);

/*!
 * \brief Platform de-initialization
 */
void PL_Deinit(void);


#endif /* PLATFORM_H_ */
