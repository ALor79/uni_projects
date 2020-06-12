/*Write	a	program	that	reads	in	an	integer,	N,	and	computes	the	first	N	Pell
numbers.	The	Pell sequence	of	integers	is	{0,	1,	2,	5,	12,	29,	70,	169,	408,	
985,	2378	…}	and	is	defined	as
P[0]	=	0,	P[1]	=	1,	P[N]	=	2*P[N-1]	+	P[N-2]*/
#include <stdio.h>

int main() {
    //declaring some variables
    int N;
    int answer;
    int pel1=0;
    int pel2=1;
    //getting the user's input
    printf("enter the value for N");
    scanf ("%d",&N);
    //checking wether user has entered 2 or 1
    if (N ==1 )
    {
        printf("%d\n",0);
    }
    else if (N ==2)
    {
        printf("%d\t%d\n",0,1);
    }
    else //if theuser has given input 3 or higher
    {
        for (int i = 0; i < (N-2); i++) 
        {
            //calculating values
            answer = pel1+2*pel2;
            //assigning new values to previous varialbes
            pel1= pel2;
            pel2= answer;
            printf("%d\t",pel2);

        }
    }
    return 0;
}//gcc pell.c -o pell.exe