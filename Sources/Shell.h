/*
 * Shell.h
 *
 *  Created on: 30.10.2014
 *      Author: tbsimmen

 * This module implements a command line interface to the application.
 */

#ifndef SHELL_H_
#define SHELL_H_

/*!
 * \brief Sends a string to the shell/console stdout
 * \param msg Zero terminated string to write
 */
void SHELL_SendString(unsigned char *msg);

/*! \brief Shell Module initialization, creates Shell task */
void SHELL_Init(void);

/*! \brief Shell driver de-initialization */
void SHELL_Deinit(void);

#endif /* SHELL_H_ */


#ifndef SHELL_H_
#define SHELL_H_





#endif /* SHELL_H_ */
