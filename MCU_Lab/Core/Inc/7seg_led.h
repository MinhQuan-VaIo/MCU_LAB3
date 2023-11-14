/*
 * 7seg_led.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Minhq
 */

#ifndef INC_7SEG_LED_H_
#define INC_7SEG_LED_H_

#include "main.h"
#define MAX_LED 4

void display(int val);
void update7SEG(int index);
void update_buffer();


#endif /* INC_7SEG_LED_H_ */
