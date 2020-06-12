/*factorial	of	a	number	N:
Using while loops*/
#include<stdio.h>

int main() 
{
    int n;
    int answer =1;
    //asking the user for input
    printf("please enter the number that you want the factorial of");
    scanf ("%d",&n);
    // doing the factorial's calculation
    int i = 1;
    while ( i <= n )
    {
        answer*=i;
        printf("%d\n",answer);//displaying
        i++;
    }
    
        
return 0;
}

//gcc Factorial_up_While.c -o factUpWh.exe