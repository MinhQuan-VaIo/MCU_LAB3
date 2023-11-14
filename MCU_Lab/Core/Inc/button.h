/*
 * button.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Minhq
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define NUMBER_OF_BUTTON 3
#define TimeOutForKey 50
extern int button1_flag;

void getKeyInput();
#endif /* INC_BUTTON_H_ */
