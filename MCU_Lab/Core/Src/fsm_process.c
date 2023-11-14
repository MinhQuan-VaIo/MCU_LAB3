/*
 * fsm_process.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Minhq
 */
#include "fsm_process.h"
#include "main.h"


int lightTime_red = 5;
int lightTime_amber = 2;
int lightTime_green = 3;
void fsm_function(){
	switch (status) {
		case INIT:
			HAL_GPIO_WritePin(GPIOB, LED_RED1_Pin | LED_AMBER1_Pin | LED_GREEN1_Pin , SET);
			HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin | LED_AMBER2_Pin | LED_GREEN2_Pin , SET);
			status = RED1_GREEN2;
			road1 = lightTime_red;
			road2 = lightTime_green;
			break;

		case RED1_GREEN2:
			HAL_GPIO_WritePin(GPIOB, LED_RED1_Pin | LED_GREEN2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, LED_AMBER1_Pin | LED_GREEN1_Pin |LED_RED2_Pin | LED_AMBER2_Pin , SET);
			if(road2 <= 0){
				status = RED1_AMBER2;
				road2 = lightTime_amber;
			}
			break;
		case RED1_AMBER2:
			HAL_GPIO_WritePin(GPIOB, LED_RED1_Pin | LED_AMBER2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, LED_AMBER1_Pin | LED_GREEN1_Pin |LED_RED2_Pin | LED_GREEN2_Pin , SET);
			if(road2 <= 0){
				status = GREEN1_RED2;
				road1 = lightTime_green;
				road2 = lightTime_red;
			}
			break;
		case GREEN1_RED2:
			HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin | LED_GREEN1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, LED_AMBER1_Pin | LED_AMBER2_Pin |LED_RED1_Pin | LED_GREEN2_Pin , SET);
			if(road1 <= 0){
				status = AMBER1_RED2;
				road1 = lightTime_amber;
			}
			break;
		case AMBER1_RED2:
			HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin | LED_AMBER1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, LED_GREEN1_Pin | LED_AMBER2_Pin |LED_RED1_Pin | LED_GREEN2_Pin , SET);
			if(road1 <= 0){
				status = RED1_GREEN2;
				road1 = lightTime_red;
				road2 = lightTime_green;
			}
			break;
		default:
			break;
	}
}

