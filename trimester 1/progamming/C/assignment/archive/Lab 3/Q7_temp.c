/*Write	a	program	to	convert	Celsius	to	Fahrenheit,	reading	the	Celsius	
value	from	the	keyboard.
The	formula	for	the	conversion	is		Fahrenheit	=	Celsius * (9/5) +	32*/
#include<stdio.h>
int main (){
    //defining a variable to store the tempreture in celsius
    float cel;
    // asking the user for the tempreture in celsius
    printf ("what tempreture you wish to convert (in Fahrenheit)?\n");
    scanf("%f", &cel);
    // definfg a variable to store the converted tempreture in Fahrenheit 
    float InFar	=	cel * (9.0/5.0) +	32;
    //displaying the answer
    printf("the tempreture in Fahrenheit is %.7f\n", InFar);
    return 0;
}
//gcc Q7_temp.c -o Q7.exe