/*. Write	a	function	to	compute	the	roots	of	a	quadratic	equation,	which	
takes	three	floating	point	numbers	a,	b, c as	arguments,	as	well	as	an	
integer	argument,	to	indicate	which	of	the	two	roots	to	return. Write	a	
main	program	that	calls	this	function to	calculate	the	root	and	then	calls	
the	function	defined	in	Question	1 to	check	that	your	root	is	correct.*/
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
struct root
{
    double one;
    double two;
};

struct root quadratic(double a, double b, double c);
int main(void)
{
    double a;
    printf("enter the value of a:");
    scanf("%lf", &a);
    double b;
    printf("enter the value of b");
    scanf("%lf", &b);
    double c;
    printf("enter the value of c:");
    scanf("%lf", &c);

    double delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        int which;
        printf("do you want the first or second root (enter 1 or 2):");
        scanf("%d", &which);
        struct root x = quadratic(a, b, c);
        if (which == 1)
        {
            printf("the first root is: %lf\n", x.one);
        }
        else if (which == 2)
        {
            printf("the second root is: %lf\n", x.two);
        }
    }else if (delta==0)
    {
        struct root x = quadratic(a, b, c);
        printf("there is one root and it  is: %lf\n", x.one);
    }else
    {
        printf("there is no real roots\n");
    }
    

    return 0;
}
struct root quadratic(double a, double b, double c)
{
    struct root x;
    double delta = b * b - 4 * a * c;

    x.one = (-b - sqrt(delta)) / (2 * a);
    x.two = (-b + sqrt(delta)) / (2 * a);
    return x;
}