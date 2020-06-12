/*Write	a	program	to	read	two	whole	numbers,	subtract	the	1st number	
from	the	second	number	and	display	the	result:*/
#include<stdio.h>
#include<math.h>
int main (){
 
    int Num1, Num2;
    // asking the user for the inputs
    printf ("Enter the first number\n");
    scanf("%d", &Num1);

    printf ("Enter the second number\n");
    scanf("%d", &Num2);
    // subtracting the numbers and getting the absolute value of them
    int answer = sqrt((Num1- Num2)*(Num1- Num2));
    //displaying the answer
    printf ("\nthe answer is %d\n", answer);    

    return 0;
}
//gcc Q9.c -o Q9.exe
