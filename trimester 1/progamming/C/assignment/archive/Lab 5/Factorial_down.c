/*For	factorial,	computing	from	N	downwards,	rather	than	1	
upwards.*/
#include<stdio.h>

int main() 
{
    //declare variables
    int n;
    long answer =1;
    //get and input from the user
    printf("entre a value for N");
    scanf ("%d",&n);

    while(n>1)
        {
            //calculation
            answer = answer*n;
            //displaying the answer
            printf("%ld\n",answer);
            //decrementation of n
            n--;
        }
        
return 0;
}

//gcc Factorial_down.c -o factD.exe