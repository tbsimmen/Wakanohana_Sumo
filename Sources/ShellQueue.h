/*
 * ShellQueue.h
 *
 *  Created on: 07.11.2014
 *      Author: tbsimmen
 */

#ifndef SHELL_QUEUE_C_
#define SHELL_QUEUE_C_

/*!
 * \brief Sends a string to the queue. Note that if the queue is full, it will block.
 * \param str Pointer to the string.
 */
void SQUEUE_SendString(const unsigned char *str);

/*!
 * \brief Returns the number of elements (characters) in the queue.
 * \return Number of characters in the queue.
 */
unsigned short SQUEUE_NofElements(void);

/*!
 * \brief Receives an a message character from the queue, and returns immediately if the queue is empty.
 * \return Message character, or '\0' if there was no message.
 */
unsigned char SQUEUE_ReceiveChar(void);

/*! \brief Initializes the queue module */
void SQUEUE_Init(void);

/*! \brief Deinitializes the queue module */
void SQUEUE_Deinit(void);

#endif /* SHELL_QUEUE_C_ */
