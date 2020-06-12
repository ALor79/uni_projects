/*Write	a program	to read two	whole numbers, multiply the	1st number	by	
the	second number and	display	the	result	in	the	form:
8 multiplied by 6 gives 48*/
#include<stdio.h>
#include<math.h>
int main (){
    
    int Num1, Num2;
    // asking the user for the inputs
    printf ("Enter the first number\n");
    scanf("%d", &Num1);

    printf ("Enter the second number\n");
    scanf("%d", &Num2);
    //multiplying the numbers
    int answer = Num1*Num2;
    //display the answer
    printf ("\n the answer is %d\n", answer);    

    return 0;
}
//gcc Q11.c -o Q11.exe
