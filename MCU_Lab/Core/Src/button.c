///*
// * button.c
// *
// *  Created on: Nov 7, 2023
// *      Author: Minhq
// */
#include "button.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  200;
int button1_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(){
	//TODO
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button1_flag = 1;
}

void getKeyInput(){
  KeyReg0 = KeyReg1;
  KeyReg1 = KeyReg2;
  //Add your button here
  KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);

  if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
    if (KeyReg3 != KeyReg2){
      KeyReg3 = KeyReg2;

      if (KeyReg2 == PRESSED_STATE){
    	  //TODO
        TimeOutForKeyPress = 200;
        subKeyProcess();
      }
    }else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
        	//TODO
        	if (KeyReg2 == PRESSED_STATE){
        	    	  //TODO
        	        subKeyProcess();
        	}
        	TimeOutForKeyPress = 200;
        }
    }
  }
}

