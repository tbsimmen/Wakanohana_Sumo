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
	#define PL_IS_FRDM 1 //(defined(PL_BOARD_IS_FRDM)) 		/*!< Macro is defined through compiler option for the FRDM board */
	#define PL_IS_ROBO 0 //(defined(PL_BOARD_IS_ROBO))   	/*!< Macro is defined through compiler option for the Robot board */ /*<- sog. 'Line Continuation')*/


	// WHAT HARDWARE IS AVALIABLE?
	#define PL_HAS_LED            (1)
	  /*!< Set to 1 to enable LED support, 0 otherwise */
	#define PL_HAS_EVENTS         (1)
	  /*!< Set to 1 to enable event support, 0 otherwise */
	#define PL_HAS_TIMER          (1)
	  /*!< Set to 1 to enable timer support, 0 otherwise */
	#define PL_HAS_KEYS           (1)
	  /*!< Set to 1 to enable key/push button support, 0 otherwise */
	#define PL_HAS_KBI            (1)
	  /*!< Set to 1 to enable key interrupt support, 0 otherwise */
	#define PL_HAS_KBI_NMI        (1 && PL_IS_FRDM && PL_HAS_JOYSTICK)
	  /*!< Set to 1 for special case on NMI/PTA pin on FRDM board, 0 otherwise */
	#define PL_HAS_RESET_KEY      (0 && PL_IS_FRDM && PL_HAS_KEYS)
	  /*!< Set to 1 to use reset switch on FRDM as button, 0 otherwise */
	#define PL_HAS_JOYSTICK       (1 && PL_IS_FRDM && PL_HAS_KEYS)
	  /*!< Set to 1 to enable joystick shield support, 0 otherwise */
	#define PL_HAS_MEALY          (0 && PL_NOF_LEDS>=1 && PL_NOF_KEYS>=1)
	  /*!< Set to 1 to enable Mealy FSM, 0 otherwise */
	#define PL_HAS_SHELL          (1 && (PL_IS_FRDM || (PL_IS_ROBO && PL_HAS_USB_CDC)))
	  /*!< Set to 1 to enable shell, 0 otherwise */
	#define PL_HAS_TRIGGER        (1 && PL_HAS_TIMER)
	  /*!< Set to 1 to enable triggers, 0 otherwise */
	#define PL_HAS_BUZZER         (1 && PL_HAS_TRIGGER && PL_IS_ROBO)
	  /*!< Set to 1 to enable buzzer, 0 otherwise */
	#define PL_HAS_DEBOUNCE       (1 && PL_HAS_KEYS)
	  /*!< Set to 1 to enable triggers, 0 otherwise */
	#define PL_HAS_RTOS           (1)
	  /*!< Set to 1 if using FreeRTOS, 0 otherwise */
	#define PL_HAS_USB_CDC        (1)
	  /*!< Set to 1 if using USB CDC, 0 otherwise */
	#define PL_HAS_BLUETOOTH      (1 && PL_IS_ROBO)
	  /*!< Set to 1 if using Bluetooth, 0 otherwise */
	#define PL_HAS_SHELL_QUEUE    (1 && PL_HAS_SHELL)
	  /*!< Set to 1 if using shell queues, 0 otherwise */
	#define PL_HAS_SEMAPHORE      (1)
	  /*!< Set to 1 if using semaphore labs, 0 otherwise */
	#define PL_HAS_LINE_SENSOR    (1 && PL_IS_ROBO)
	  /*!< Set to 1 if using line sensor, 0 otherwise */
	#define PL_HAS_REFLECTANCE    (1 && PL_HAS_LINE_SENSOR)
	  /*!< Set to 1 if using reflectance sensor array, 0 otherwise */
	#define PL_HAS_RTOS_TRACE     (0)



	/* if keys are using interrupts or are polled */
	#if PL_IS_FRDM
	  #define PL_KEY_POLLED_KEY1    (0)  //interrupt
	  #define PL_KEY_POLLED_KEY2    (0)
	  #define PL_KEY_POLLED_KEY3    (0)
	  #define PL_KEY_POLLED_KEY4    (0)
	  #define PL_KEY_POLLED_KEY5    (1)	//polled
	  #define PL_KEY_POLLED_KEY6    (1)
	  #define PL_KEY_POLLED_KEY7    (0)
	#elif PL_IS_ROBO
	  #define PL_KEY_POLLED_KEY1    (0)
	#endif


	/* DEFINE HARDWARE IN DETAIL*/
	#if PL_IS_FRDM
		#if PL_HAS_JOYSTICK
			#define PL_NOF_LEDS       (2)
			  /*!< FRDM board has 2 LEDs (red is used by joystick shield) */
			#define PL_NOF_KEYS       (7)
			  /*!< FRDM board has no keys without joystick shield */
		#else
			#define PL_NOF_LEDS       (3)
			 /*!< FRDM board has up to 3 LEDs (RGB) */
			#if PL_HAS_RESET_KEY
				#define PL_NOF_KEYS       (1)
				 /*!< FRDM board with using the reset button */
			#else
				#define PL_NOF_KEYS       (0)
				 /*!< FRDM board has no keys without joystick shield */
			#endif
		#endif
	#elif PL_IS_ROBO
		#define PL_NOF_LEDS       (2)
		 /*!< We have up to 2 LED's on the robo board */
		#define PL_NOF_KEYS       (1)
		 /*!< We have up to 1 push button */
	#else
		//#error "unknown configuration?"
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
