/*
 * fsm_mode.c
 *
 *  Created on: Nov 16, 2023
 *      Author: Minhq
 */
#include "global.h"
#include "fsm_mode.h"
void fsm_manual_func(){
	switch (status) {
		case MAN_INIT:
			HAL_GPIO_WritePin(GPIOB, LED_RED1_Pin|LED_RED2_Pin|LED_AMBER1_Pin|LED_AMBER2_Pin|
					LED_GREEN1_Pin|LED_GREEN2_Pin, RESET);
			setTimer3(1000);
			break;
		default:
			break;
	}
}


