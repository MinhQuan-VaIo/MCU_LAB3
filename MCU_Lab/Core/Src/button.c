/*
 * button.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Minhq
 */
#include "button.h"
static GPIO_PinState keyReg1[NUMBER_OF_BUTTON];
static GPIO_PinState keyReg2[NUMBER_OF_BUTTON];
static GPIO_PinState keyReg3[NUMBER_OF_BUTTON];
static GPIO_PinState Pin_buffer[NUMBER_OF_BUTTON];

static int button_flag[NUMBER_OF_BUTTON];
static int counter[NUMBER_OF_BUTTON];

uint16_t Pin_number[NUMBER_OF_BUTTON] = {MODE_Pin, ADD_Pin, CONFIRM_Pin};

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	for(int i = 0; i < NUMBER_OF_BUTTON; i++){
		keyReg1[i] = keyReg2[i];
		keyReg2[i] = Pin_buffer[i];
		Pin_buffer[i] = HAL_GPIO_ReadPin(GPIOA, Pin_number[i]);

		if((keyReg1[i] == keyReg2[i]) && (keyReg2[i] == Pin_buffer[i])){
			if(keyReg3[i] != Pin_buffer[i]){
				keyReg3[i] = Pin_buffer[i];
				if(Pin_buffer[i] == PRESSED_STATE){
					//TO DO
					button_flag[i] = 1;
					counter[i] = 0;
				}
			}else{
				counter[i]++;
				if(counter[i] == TimeOutForKey){
					//TO DO
					keyReg3[i] = NORMAL_STATE;
				}

			}
		}
	}
}



