/*Write	a	program	that	declares	a	float sum,		reads	in	an	integer	value	N
and	computes	and	displays	the	sum	of	the	inverse	of	the	first	N	numbers	
i.e.	computes	sum = 1 + 1/2 +1/3 + 1/4 + 1/5 + … + 1/N.	
Try	the	program	for	very	large	values	of	N	e.g.	N=1000000000.		Do	you	
notice	anything	strange	about	the	result?	How	about	if	you	declare	
double sum i.e.	use	a	double-precision	floating-point	value	for	the	sum	
instead?*/
#include<stdio.h>
void small(int T);
void big(int T);

int main(void) {
    int n;
        printf("please enter a value for N");
        scanf ("%d",&n);
    //asking the user for input

    if (n<=1000000)     // according to https://www.tutorialspoint.com/cprogramming/c_data_types.htm float can handle up 6 decimal place
    {
        small(n);
    }

    else
    {
        big(n);
    }


}
void small(int T)// void function for small numbers
{
    // summing the numbers up
    float i = 1;
    float answer =0;

    while ( i <= T)
    {
        answer+=(1/i);
  
        i++;
        
    }
    printf("answer using a single-precision floating-point : %f\n",answer);

    
    //displaying

}


void big( int T)    //void function for big numbers
{
    // summing the numbers up
    double i = 1;
    double answer =0;
    while ( i <= T)
    {
        answer+=(1/i);
        i++;
        
    }
    printf("answer using a double-precision floating-point : %lf\n",answer);//displaying

}
//gcc sum2.c o- sum2.exe