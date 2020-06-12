//the	Fibonacci	sequence	and	the	factorial	of	a	number	N:using for
#include<stdio.h>
#include<math.h>
int main() 
{
    //declaring some variables
    int count;
    int answer;
    int fib1=1;
    int fib2=1;
    //getting the user's input
    printf("enter the value for N");
    scanf ("%d",&count);

    //checking wether user has entered 2 or 1
    if (count ==1 )
    {
        printf("%d\n",1);
    }
    else if (count ==2)
    {
        printf("%d\t%d\n",1,1);
    }
    else
    {
        printf("%d\t%d\t",1,1);
        //defining the loop
        for (int i = 0; i < (count-2); i++) 
        {
            //calculating values
            answer = fib1+fib2;
            //assigning new values to previous varialbes
            fib1= fib2;
            fib2= answer;
            printf("%d\t",fib2);

        }
        
    }
    
    

        
return 0;
}

//gcc fibonacciFor.c -o fibF.exe