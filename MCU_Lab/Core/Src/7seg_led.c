/*
 * 7seg_led.c
 *
 *  Created on: Nov 14, 2023
 *      Author: Minhq
 */
#include "main.h"
#include "7seg_led.h"
#include "global.h"
int led_index = 0;
int led_buffer [4];
int scan_timer = 25000;
void scan_seg_led(){
	update_buffer();
	if(timer2_flag == 0){
		update7SEG(led_index++);
		if(led_index > 3) led_index = 0;
		setTimer2(scan_timer);
	}
}
void update_buffer() {
	led_buffer[0] = road1 / 10;
	led_buffer[1] = road1 % 10;

	led_buffer[2] = road2 / 10;
	led_buffer[3] = road2 % 10;
}

void display(int val){
	switch (val){
		case 0:
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin |SEG0_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG6_Pin , SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin , RESET);
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin| SEG6_Pin , SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG3_Pin | SEG4_Pin | SEG6_Pin , RESET);
			HAL_GPIO_WritePin(GPIOB, SEG2_Pin | SEG5_Pin , SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin |SEG0_Pin | SEG3_Pin | SEG6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin | SEG5_Pin , SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin |SEG5_Pin | SEG6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG3_Pin| SEG4_Pin , SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin |SEG5_Pin | SEG6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG4_Pin , SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin |  SEG4_Pin| SEG5_Pin | SEG6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin , SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin , RESET);
			HAL_GPIO_WritePin(GPIOB, SEG3_Pin | SEG4_Pin | SEG5_Pin |  SEG6_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin |SEG0_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin |SEG6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin |SEG0_Pin | SEG3_Pin | SEG6_Pin | SEG5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, SEG4_Pin , SET);
			break;
	}
}

void update7SEG (int index ){
  switch ( index ){
  	case 0:
  		// Display the first 7 SEG with led_buffer [0]
  		HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
  		HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN3_Pin, SET);
  		display(led_buffer[0]);
  		break ;
  	case 1:
  		// Display the second 7 SEG with led_buffer [1]
  		HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
  		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin|EN3_Pin, SET);
  		display(led_buffer[1]);
  		break ;
  	case 2:
  		// Display the third 7 SEG with led_buffer [2]
  		HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
  		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN3_Pin, SET);
  		display(led_buffer[2]);
  		break ;
  	case 3:
  		// Display the forth 7 SEG with led_buffer [3]
  		HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
  		HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN2_Pin, SET);
  		display(led_buffer[3]);
  		break ;
  	default :
  		break ;
  	}
  }

