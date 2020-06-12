/*Write	a	function	to	calculate	the	monthly	repayment	required	to	pay	off	a	
loan	of	P euro	after	n years	when	the	annual	interest	rate	is	r %.		The	
required	formula is:
��������� = ��,
1 − (1 + �,)2345
					where	r, is	the	monthly	interest	rate	given	by	�, = 6
34×388 .	For	example,	
when	P=€200,000,	and	n	=	20 years and	r=4%,	the	function	should	return	
€1,211.96*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
double repayment(double p, double n, double r);
int main()
{
    double p, n, r = 0;
    printf("enter p:");
    scanf("%lf", &p);
    printf("enter r:");
    scanf("%lf", &r);
    printf("enter n:");
    scanf("%lf", &n);
    printf("%.2lf\n", repayment(p, n, r));

    return 0;
}

double repayment(double p, double n, double r)
{
    double rm = r / (12 * 100);
    double base = 1 + rm;
    double power = -12 * n;
    double repayment = (p * rm) / (1 - pow(base, power));
    return repayment;
}
