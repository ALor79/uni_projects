/*Write	a	program	to	convert	Celsius	to	Fahrenheit,	reading	the	Celsius	
value	from	the	keyboard.
The	formula	for	the	conversion	is		Fahrenheit	=	Celsius * (9/5) +	32*/
#include<stdio.h>
int main (){
    //defining a variable to store the tempreture in Fahrenheit
    float far;
    // asking the user for the tempreture in Fahrenheit
    printf ("what tempreture you wish to convert (in Fahrenheit)?\n");
    scanf("%f", &far);
    // definfg a variable to store the converted tempreture in celsius 
    float InCel	= ( far - 32 ) * (5.0 / 9.0) ;
    //displaying the answer
    printf("the tempreture in Celsius is %.7f\n", InCel);
    return 0;
}
//gcc Q8_temp.c -o Q8.exe