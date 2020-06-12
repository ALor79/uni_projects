/*Write	a	program	that	declares	a	float sum,		reads	in	an	integer	value	N
and	computes	and	displays	the	sum	of	the	inverse	of	the	first	N	numbers	
i.e.	computes	sum = 1 + 1/2 +1/3 + 1/4 + 1/5 + … + 1/N.	
*/
#include<stdio.h>

int main(void) {
    int n;
    float answer =0;
    //asking the user for input
    printf("please enter a value for N");
    scanf ("%d",&n);
    // summing the numbers up
    float i = 1;
    while ( i <= n)
    {
        answer+=(1/i);
        i++;
        
    }
    printf("%f\n",answer);//displaying
}//gcc sum.c -o sum.exe

