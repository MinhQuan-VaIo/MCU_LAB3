/*
 * software_timer.h
 *
 *  Created on: Oct 12, 2023
 *      Author: Minhq
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;
extern int timer5_flag;
#define TIMER_CYCLE 10

extern int timer0_mode_debounce_flag;
extern int timer0_mode_debounce_counter;

void set_Timer_mode_debounce(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void timerRun();
void clearTimer1();

#endif /* INC_SOFTWARE_TIMER_H_ */
