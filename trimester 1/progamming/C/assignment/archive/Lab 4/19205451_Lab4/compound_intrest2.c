#include<stdio.h>
#include<math.h>

int main ()
{   //declaring variables
    double p , r, n ,A;
    double k = 12.0;

    //asking user to determine what the unknown variable is
    printf("which of the following is the unknown? A ,r , n or P?");
    char answer = getchar();

    //checking what input the user has given
    if (answer == 'A')
    {   //taking user's input for value
        printf("Enter a value for the intial amount of money i.e. P\n");
        scanf("%lf",&p);
        printf("Enter the number of years i.e. n\n");
        scanf("%lf",&n);
        printf("Enter a value for The simple interest rate i.e. r\n");
        scanf("%lf",&r);

        //computation
        double X=r/(k*100);
        A=p*(pow(1+X, (n*k))) ;
        //displaying the answer
        printf("final value in euros is equal to %lf\n", A);
    }
    else if (answer == 'n')
    {   
        //taking user's input for value
        printf("Enter a value for the intial amount of money i.e. P\n");
        scanf("%lf",&p);
        printf("Enter the final amount of money i.e. A\n");
        scanf("%lf",&A);
        printf("Enter a value for The simple interest rate i.e. r\n");
        scanf("%lf",&r);

        //computation
        double firstLog=A/p;
        double secondLog= A+r/(100*k);
        n = (log10(firstLog)/log10(secondLog))/k;
        //displaying the answer
        printf("it takes %lf years\n", n);
    }
    else if (answer == 'p' || answer == 'P')
    {   
        //taking user's input for value
        printf("Enter the number of years i.e. n\n");
        scanf("%lf",&n);
        printf("Enter the final amount of money i.e. A\n");
        scanf("%lf",&A);
        printf("Enter a value for The simple interest rate i.e. r\n");
        scanf("%lf",&r);


        //computation
        double X = 1+r/100;
        p = A/pow(X,(n*k));
        //displaying the answer
        printf("the initial amount of money should be %lf\n", p);
    }
    else if (answer == 'r' || answer == 'R')
    {   
        //taking user's input for value
        printf("Enter the number of years i.e. n\n");
        scanf("%lf",&n);
        printf("Enter the final amount of money i.e. A\n");
        scanf("%lf",&A);
        printf("Enter a value for the intial amount of money i.e. P\n");
        scanf("%lf",&p);

        //computation
        double X = 1/(n*k);
        r = (pow((A/p),X)-1)*100*k;
        //displaying the answer
        printf("the intrest rate should be %lf percent\n", r);
    }
    else
    {
        printf("Invalid answer");
    }
    
        


    

return 0 ;


    
}//gcc compound_intrest2.c -o compound_intrest2.exe