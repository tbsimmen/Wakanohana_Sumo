/*
 * Buzzer.h
 *
 *  Created on: 16.10.2014
 *      Author: tbsimmen
 *
 *
 *      This module implements the driver for the buzzer.
 */


#ifndef BUZZER_H_
#define BUZZER_H_

#include "Platform.h"

/*!
 * \brief Let the buzzer sound for a specified time.
 * \param freqHz Frequency of the sound. Ignored if the buzzer is not supporting it.
 * \param durationMs Duration in milliseconds.
 * \return Error code, ERR_OK if everything is fine.
 */
uint8_t BUZ_Beep(uint16_t freqHz, uint16_t durationMs);

/*!
 * \brief Initialization of the driver
 */
void BUZ_Init(void);

/*!
 * \brief De-initialization of the driver
 */
void BUZ_Deinit(void);

#endif /* BUZZER_H_ */
