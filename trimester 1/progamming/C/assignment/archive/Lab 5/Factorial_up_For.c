/*factorial	of	a	number	N:
Using for loops*/
#include<stdio.h>

int main() 
{
    int n;
    int answer =1;
    //asking the user for input
    printf("please enter the number that you want the factorial of");
    scanf ("%d",&n);
    // doing the factorial's calculation
    for (int i = 1; i <= n; i++)
    {
        answer*=i;
        printf("%d\n",answer);//displaying
    }
    
        
return 0;
}

//gcc Factorial_up_For.c -o factUpFor.exe