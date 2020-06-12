//the	Fibonacci	sequence	and	the	factorial	of	a	number	N:using while
#include<stdio.h>
#include<math.h>
int main() 
{
    //declaring some variables
    int count;
    int answer;
    int F1=1;
    int F2=1;
    
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
        int i = 0;
        while ( i < (count-2)) 
        {
            //calculating values
            answer = F1+F2;
            //assigning new values to previous varialbes
            F1= F2;
            F2= answer;
            printf("%d\t",F2);
            i++;

        }
        
    }
    
    

        
return 0;
}

//gcc fibonacci_while.c -o fibW.exe