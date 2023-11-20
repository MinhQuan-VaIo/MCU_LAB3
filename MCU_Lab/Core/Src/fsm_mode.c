/*
 * fsm_mode.c
 *
 *  Created on: Nov 16, 2023
 *      Author: Minhq
 */
#include "global.h"
#include "fsm_mode.h"
int temp_time = 0;
void blinky_red(){
	if(timer3_flag == 1){
		HAL_GPIO_TogglePin(GPIOB, LED_RED1_Pin | LED_RED2_Pin);
		setTimer3(500);
	}
}
void blinky_amber(){
	if(timer3_flag == 1){
		HAL_GPIO_TogglePin(GPIOB, LED_AMBER1_Pin | LED_AMBER2_Pin);
		setTimer3(500);
	}
}
void blinky_green(){
	if(timer3_flag == 1){
		HAL_GPIO_TogglePin(GPIOB, LED_GREEN1_Pin | LED_GREEN2_Pin);
		setTimer3(500);
	}
}
void fsm_manual_func(){
	switch (status) {
		case MAN_INIT:
			HAL_GPIO_WritePin(GPIOB, LED_RED1_Pin|LED_RED2_Pin|LED_AMBER1_Pin|LED_AMBER2_Pin|
					LED_GREEN1_Pin|LED_GREEN2_Pin, RESET);
			setTimer3(250);
			status = MAN_RED;
			temp_time = lightTime_red;
			road2 = 2;
			break;
		case MAN_RED:
			blinky_red();
			if(isButtonPressed(0)){
				HAL_GPIO_WritePin(GPIOB, LED_RED1_Pin|LED_RED2_Pin, RESET);
				status = MAN_AMBER;
				temp_time = lightTime_amber;
				road2 = 3;
				setTimer3(250);
			}
			if(isButtonPressed(1)){
				if(temp_time > 99) temp_time = 0;
				else temp_time++;
			}
			if(isButtonPressed(2)){
				lightTime_red = temp_time;
			}
			break;
		case MAN_AMBER:
			blinky_amber();
			if(isButtonPressed(0)){
				HAL_GPIO_WritePin(GPIOB, LED_AMBER1_Pin|LED_AMBER2_Pin, RESET);
				status = MAN_GREEN;
				temp_time = lightTime_green;
				road2 = 4;
				setTimer3(250);
			}
			if(isButtonPressed(1)){
				if(temp_time > 99) temp_time = 0;
				else temp_time++;
			}
			if(isButtonPressed(2)){
				lightTime_amber = temp_time;
			}
			break;
		case MAN_GREEN:
			blinky_green();
			if(isButtonPressed(0)){
				if(lightTime_amber + lightTime_green != lightTime_red){
					lightTime_red = 5;
					lightTime_amber = 2;
					lightTime_green = 3;
				}
				status = INIT;
			}
			if(isButtonPressed(1)){
				if(temp_time > 99) temp_time = 0;
				else temp_time++;
			}
			if(isButtonPressed(2)){
				lightTime_green = temp_time;
			}
			break;
		default:
			break;
	}
	if(status >= MAN_INIT){
		road1 = temp_time;
	}

}


