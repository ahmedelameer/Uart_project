/*
 * Special_func.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Mohamed ELameer
 */
#include"MICRO_setting.h"
/*converting any integers to string*/
void intToStr(uint8_t inputNum, uint8_t*outStr){
	/* using reminder as your giving number to can modify it without changing the giving original
	 * number   ex: reminder =123 or -123
	 */
/* using reminder as your giving number to can modify it without changing the giving original
	 * number   ex: reminder =123 or -123
	 */
	uint8_t reminder=inputNum;
	uint8_t count_digit=0,i,arr_lenght;
	/* counting the giving number digits*/
	while(reminder !=0){
		count_digit++;
		reminder/=10;
	}
	/* the array length is the same of number digits*/
	arr_lenght=count_digit;
	/*if the number giving is negative number ex:-123*/
	if(inputNum<0){
		/*consider your number is -123 this will mean 3 digits + 1 minis
		 * the total size should be 4 =3+1
		 */
		arr_lenght=count_digit+1;
		for(i=0;i<arr_lenght;i++){
			/*but the first elemnt of the string is the minis*/
			if(arr_lenght-i-1==0)
				outStr[0]='-';
			/*except that put the number in the right place
			 * if ex:-123
			 * arr[3]=3   arr[2]=2  arr[1]=1  arr[0]=-
			 */
			else{
				/*(inputNum*-1) to save the number without any sign as string*/
				outStr[arr_lenght-i-1]=((inputNum*-1)%10)+'0';
				inputNum/=10;
			}
		}
	}
	/*if the number is postive*/
	else{
		/*make the same sequance to put the number in the right place*/
		for(i=0;i<count_digit;i++){
			outStr[count_digit-i-1]=(inputNum%10)+'0';
			inputNum/=10;
		}
	}
	/*put null into the last place */
	outStr[arr_lenght]='#'; //put the last # to recieve from terminal
	outStr[arr_lenght+1]='\0';
}






uint8_t strToInt(uint8_t *inputString){
	uint32_t count = 0;
	uint8_t result=0;
	uint32_t weight=1;
	while(inputString[count] != '\0'){
		count++;
	}

	if(inputString[0] == '-'){
		for(count-=1 ; count>0 ; count--){
			result += (inputString[count]-'0')*weight;
			weight*=10;
		}
		result*=-1;
	}
	else{
		for(count-=1 ; count>0 ; count--){
			result += (inputString[count]-'0')*weight;
			weight*=10;
		}
		result += (inputString[count]-'0')*weight;
	}
	return result;
}
