/*
 * global.h
 *
 *  Created on: Nov 14, 2023
 *      Author: Minhq
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "7seg_led.h"
#include "software_timer.h"
#include "button.h"
#include "fsm_process.h"

extern int road1;
extern int road2;
extern int status;
#define INIT 			0
#define RED1_GREEN2 	1
#define RED1_AMBER2 	2
#define GREEN1_RED2 	3
#define AMBER1_RED2 	4

#define MAN_INIT 		14
#define MAN_RED			15
#define MAN_AMBER		16
#define MAN_GREEN		17
#endif /* INC_GLOBAL_H_ */
