/*Compound	interest	can	be	computed	using	the	formula

Here	A	is	an	amount	of	money (in	Euro)	and	the	formula	calculates	how	
much	money	A accumulates	if	some	initial	amount	of	money	P	(the	
“principal”)	is	deposited	in	a	bank	account	and	left	there	for	n years.	The	
simple	interest	rate	is	r% per	annum,	k	determines	the	frequency	with	
which	interest	is	added	to	the	account.		For	instance, if	k==12,	then	interest	
is	added	every	month.*/
#include<stdio.h>
#include<math.h>
#define Euro "\u20AC"
int main (){
    //defining variables
    double p , r, n ,A;
    //definig constant k
    double k = 12.0; 

    //asking user for values
    printf("Enter a value for the intial amount of money i.e. P\n");
    scanf("%lf",&p);
    printf("Enter the number of years i.e. n\n");
    scanf("%lf",&n);
    printf("Enter a value for The simple interest rate i.e. r\n");
    scanf("%lf",&r);
    //computation of A
    double X=r/(k*100);

    A= p*(pow(1+X, (n*k))) ;
    //returning the final value
    printf("final value is equal to %s%lf\n",Euro, A);

    
    }
//gcc compound_intrest.c -o compound_intrest.exe