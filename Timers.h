/*
 * Timers.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */

#ifndef TIMERS_H_
#define TIMERS_H_


#include "Timer_config.h"
#include "MICRO_setting.h"

#define NULL_PTR    ((void*)0)

extern uint8_t N_Sec,N_Min,N_Hour;

typedef enum{
	T0,T2
}t_type;

extern uint8_t Time_update;
void Delay_ms(uint64_t n_milleSec,t_type timer);

void Dely_ms_service(t_type timer,uint64_t time_MS,void(*ptr_display)(void));

void timer_init(void );

void Timer_Square_Wave_Init(void);

void Timer_setCallBack(void(*a_ptr)(void));

void Toggle_half_sec(void);


void Toggle_Sec(void);

extern uint8_t duty_percentage;

void SPEED(void);

void TIMER_PWM (uint8_t timer, uint8_t duty);

void start_count_time(void);
void clear_count_time(void);

void start_clear_sec(void);

#endif /* TIMERS_H_ */
