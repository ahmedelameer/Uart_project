/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */
#include"uart.h"
#include"keypad.h"
#include"LCD.h"
#include"Timers.h"
#include"Special_fun.h"

int main(void){

	/*DDRB&=0xFB;*/
	DDRC=0;
	DDRB=0;
	//PORTB=0;
	unit8 speed[10],Spd=0,N_sec[10],sum=0,arr[3];
	LCD_init();

	UART_init();

	SREG|=(1<<7);
	LCD_displayString("speed is:");
	timer_init();

	/*arr[0]=KeyPad_getPressedKey();
	_delay_ms(300);
	arr[1]=KeyPad_getPressedKey();
	_delay_ms(300);
	arr[2]=KeyPad_getPressedKey();
	_delay_ms(300);
	Spd=arr[0]*100+arr[1]*10+arr[0];*/

	Spd=10;
	//KeyPad_getPressedKey();
	//UART_receiveString(speed);// receive intial value unit it equal to #
	Timer_setCallBack(start_count_time);
	while(1){

		if(PINB&(1<<PB2))
		{

			while( PINB&(1<<PB2));
			Spd++;
			//start_clear_sec();
		}
		if(PINC&(1<<PC4) )
		{
			if(Spd==0)
				Spd=0;
			else
			{
				while(PINC&(1<<PC4));
				Spd--;
				//start_clear_sec();

			}


		}
		if(Time_update==1)
		{
			intToStr(Spd,speed);
			UART_sendString(speed);


			Time_update=0;
		}
		LCD_gotoRawCol(0,10);
		LCD_IntToStr(Spd);
		LCD_displayString("   ");
		LCD_gotoRawCol(1,0);
		LCD_IntToStr(N_Sec);
		LCD_displayString("   ");




	}

}
