#include<stdio.h>

int main()
{
    //declaring variables
    long n, count, j;
    long i = 3;
    //getting user's input
    printf("Enter the n:  ");
    scanf("%ld", &n);
        //error checking
    if(n <= 2)
    {
        printf("invalid input the first prime number is : 2");
    }

    
    for(i = 2; i <= n; i++)  
    {
        // checking if i is devisible by any j possible
        for(j = 2; j < i; j++)
        {
            if(i%j == 0)
            {
                break;/*if there is a j which i is devisible by the for loop breaks 
                        and therefore j will never reach the value of i and it will
                        never be printed out*/
            }
        }
        if(j == i)  
        {
            printf("%ld ", i);
            
        }
 
    }
    printf("\n");
    
    return 0;
}//gcc Q2.c -o Q2.exe