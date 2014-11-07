/*
 * Application.h
 *
 *  Created on: 26.09.2014
 *      Author: tbsimmen
 * Interface to the main application module.
 * From here the application runs and performs all tasks.
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "event.h"
/*!
 * \brief Application main start and main routine
 */
void APP_Start(void);
void APP_EventHandler(EVNT_Handle event);

#endif /* APPLICATION_H_ */
