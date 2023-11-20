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

void reset_all_flag();
void getKeyInput();
int isButtonPressed();
#endif /* INC_BUTTON_H_ */
