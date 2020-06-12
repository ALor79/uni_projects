/* Write	a	program	to	read	two	whole	numbers,	add	the	1st number	to	the	
second	number	and	display	the	result	in	the	form:
4 plus 6 is 10*/

#include<stdio.h>
#include<math.h>
int main (){
    
    int Num1, Num2;
    // asking the user for the inputs
    printf ("Enter the first number\n");
    scanf("%d", &Num1);

    printf ("Enter the second number\n");
    scanf("%d", &Num2);
    //adding the numbers
    int answer = Num1+Num2;
    //display the answer
    printf ("\n the answer is %d\n", answer);    

    return 0;
}
//gcc Q10.c -o Q10.exe

