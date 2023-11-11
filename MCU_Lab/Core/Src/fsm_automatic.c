/*
 * fsm_automatic.c
 *
 *  Created on: Nov 11, 2023
 *      Author: Minhq
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		//TO DO
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_Pin| LED_GREEN_Pin|LED_RED_Pin, SET);
		status = AUTO_RED;
		setTimer1(5000);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_Pin| LED_GREEN_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, RESET);
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(3000);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_Pin| LED_RED_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, RESET);
		if (timer1_flag == 1){
			status = AUTO_AMBER;
			setTimer1(2000);
		}
		break;
	case AUTO_AMBER:
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin| LED_RED_Pin, SET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER_Pin, RESET);
		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(5000);
		}
		break;
	default:
		break;
	}
}
