/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */
#include"uart.h"
#include"LCD.h"

#include"Special_fun.h"


int main(void){
	uint8_t Dis[10],Spd=0,flag=2;
	uint64_t sum=0,count_of_sec=0;
	DDRC=0;
	DDRB=0;
	LCD_init();
	UART_init();
	LCD_displayStrRowCol(0,0,"Ds: ");
	LCD_displayStrRowCol(1,0,"t/s: ");

	while(1){

		if(PINB&(1<<PB2)){ //start receive

			while(PINB&(1<<PB2));
			flag=1;

			LCD_gotoRawCol(0,3);
			LCD_displayString("   ");
			LCD_gotoRawCol(1,4);
			LCD_displayString("   ");
			count_of_sec=0;
			sum=0;
			/*Dis[0]=0;
				Dis[1]=0;
				Dis[2]=0;
				Dis[3]=0;*/
			Spd=0;

		}
		else if(PINC&(1<<PC4))
		{ //start recieve
			while(PINC&(1<<PC4));
			flag=0;


		}


		if(flag==1)
		{

			UART_receiveString(Dis);


			Spd=strToInt(Dis);
			count_of_sec++;
			LCD_gotoRawCol(0,3);
			LCD_IntToStr(Spd);
			LCD_displayString("  ");
			sum=sum+Spd;


			LCD_gotoRawCol(1,4);
			LCD_IntToStr(count_of_sec);



		}



		else if(flag==0)
		{
			//intToStr(sum,SUM);
			LCD_gotoRawCol(0,3);
			LCD_IntToStr(sum);



			flag=2;

			LCD_gotoRawCol(1,4);
			LCD_IntToStr(count_of_sec);



		}











		//LCD_displayString("  ");














	}
}

