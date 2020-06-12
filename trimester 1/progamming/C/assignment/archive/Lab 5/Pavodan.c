/*Write	a	program	that	reads	in	an	integer,	N,	and	computes	and	displays	
the	first	N	Pavodan numbers.	The	Pavodan sequence	of	integers	is	{1,	1,	1,	
2,	2,	3,	4,	5,	7,	9,	12,	16,	21,	28,	37,	49,	65,	86,	114,	151,	200,	265,…} and	is	
defined	as
P[1]	=	P[2]	=	P[3]	=	1,	P[N]	=	P[N-2]	+	P[N-3],	N>=4*/
#include<stdio.h>
#include<math.h>
int main() 
{
    //declaring some variables
    int count;
    int answer;
    int P1=1;
    int P2=1;
    int P3=1;
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
    else if (count ==3)
    {
        printf("%d\t%d\t%d\n",1,1,1);
    }
    else
    {
        printf("%d\t%d\t%d\t",1,1,1);
        for (int i = 0; i < (count-3); i++) 
        {
            //calculating values
            answer = P1+P2;
            //assigning new values to previous varialbes
            P1=P2;
            P2=P3;
            P3=answer;
            
            printf("%d\t",answer);

        }
        
    }
    
    

        
return 0;
}
//gcc Pavodan.c -o Pan.exe