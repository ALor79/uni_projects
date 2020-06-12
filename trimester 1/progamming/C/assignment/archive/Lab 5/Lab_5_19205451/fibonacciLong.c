/*. For	Fibonacci,	what	answers	do	you	get	when	you	print	out	50	
terms?	Is	there	anything	wrong?	How	can	you	fix	it?*/
#include<stdio.h>
#include<math.h>
int main() 
{
    //declaring some variables
    long count;
    long answer;
    long fib1=1;
    long fib2=1;
    //getting the user's input
    printf("enter the value for N");
    scanf ("%ld",&count);

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
            printf("%ld\t",fib2);

        }
        
    }
    
    

        
return 0;
}

//gcc fibonacciLong.c -o fibL.exe