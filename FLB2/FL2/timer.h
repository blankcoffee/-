/*
 * timer.h
 *
 *  Created on: 2021Äê4ÔÂ22ÈÕ
 *      Author: 23359
 */

#ifndef TIMER_H_
#define TIMER_H_

void timer_init();
void TA1_0_IRQHandler(void);



extern int ctrl_flag;
extern uint32_t TimeCnt;


extern Timer_A_PWMConfig pwm_2_4;
extern Timer_A_PWMConfig pwm_2_5;
extern Timer_A_PWMConfig pwm_2_6;
extern Timer_A_PWMConfig pwm_2_7;


#endif /* TIMER_H_ */
