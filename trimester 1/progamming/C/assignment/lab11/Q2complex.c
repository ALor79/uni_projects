/*. Write	a	function	to	compute	the	roots	of	a	quadratic	equation,	which	
takes	three	floating	point	numbers	a,	b, c as	arguments,	as	well	as	an	
integer	argument,	to	indicate	which	of	the	two	roots	to	return. Write	a	
main	program	that	calls	this	function to	calculate	the	root	and	then	calls	
the	function	defined	in	Question	1 to	check	that	your	root	is	correct.*/
#include <stdio.h>
// #include <stdbool.h>
#include <math.h>
void complex(double a, double b, double c, double *imaginary1, double *real, double *imaginary2);
void real(double a, double b, double c, double *x1, double *x2);
int main(void)
{
    double a;
    printf("enter the value of a:");
    scanf("%lf", &a);
    double b;
    printf("enter the value of b:");
    scanf("%lf", &b);
    double c;
    printf("enter the value of c:");
    scanf("%lf", &c);

    double delta = b * b - 4 * a * c;
    if (delta >= 0)
    {
        double x1, x2;
        real(a, b, c, &x1, &x2);
        if (delta == 0)
        {
            printf("there are two repeating roots and it is equal to %.2lf\n", x1);
        }
        else
        {
            int choice = 0;

            do
            {
                printf("both roots are real ,which root do you want(1 or 2):");
                scanf("%d", &choice);
                getchar();
                if (choice == 1)
                {
                    printf("the first root is equal to %.2lf\n", x1);
                }      

                else if (choice == 2)
                {
                    printf("the first root is equal to %.2lf\n", x2);
                }
            } while (choice != 2 && choice != 1);
        }
    }
    else
    {
        int choice = 0;
        double i1, i2, r;
        complex(a, b, c, &i1, &r, &i2);
        do
        {
            printf("both roots are imaginary ,which root do you want(1 or 2):");
            scanf("%d", &choice);
            getchar();

            if (choice == 1)
            {
                printf("the answer is %.2lf + %.2lf i \n", r, i1);
            }
            else if (choice == 2)
            {
                printf("the answer is %.2lf + %.2lf i \n", r, i2);
            }
        } while (choice != 2 && choice != 1);
    }

    return 0;
}
void complex(double a, double b, double c, double *imaginary1, double *real, double *imaginary2)
{
    double delta = b * b - 4 * a * c;
    *imaginary1 = -sqrt(-delta) / (2 * a);
    *imaginary2 = sqrt(-delta) / (2 * a);
    *real = -b / (2 * a);
}
void real(double a, double b, double c, double *x1, double *x2)
{
    double delta = b * b - 4 * a * c;

    *x1 = (-b - sqrt(delta)) / (2 * a);
    *x2 = (-b + sqrt(delta)) / (2 * a);
}