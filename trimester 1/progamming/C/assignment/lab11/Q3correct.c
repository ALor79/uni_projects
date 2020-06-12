/*Write	a	function	to	calculate	the	monthly	repayment	required	to	pay	off	a	
loan	of	P euro	after	n years	when	the	annual	interest	rate	is	r %.		The	
required	formula is:
 is	the	monthly	interest	rate	given	by	, = 6
34×388 .	For	example,	
when	P=€200,000,	and	n	=	20 years and	r=4%,	the	function	should	return	
€1,211.96*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define MAX 100
double repayment(double p, double n, double r);
double MakeDouble(int j, int whole[j], int i, int decimal[i]);
double correctify(char X[]);
int main()
{
    int i = 0, j = 0, k = 0;
    double p, n, r = 0;
    char P[MAX], R[MAX], N[MAX];
    printf("enter p:");
    //creates an array (string) with all the values(as chars) that the user has put in
    while ((P[i] = getchar()) != '\n')
    {
        i++;
    }
    P[i] = '\0';
    //this function removes all the extra letters (anything but . and numbers)
    p = correctify(P);
    //same as above
    printf("enter r:");
    while ((R[j] = getchar()) != '\n')
    {
        j++;
    }
    R[j] = '\0';
    r = correctify(R);
    //same as above
    printf("enter n in years:");
    while ((N[k] = getchar()) != '\n')
    {
        k++;
    }
    N[k] = '\0';
    n = correctify(N);
    //repayment function calculates the final value that we want
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
double correctify(char X[])
{
    int i = 0;
    int j = 0;
    int I = 0;

    int whole[MAX];
    int decimal[MAX];
    bool sawDot = false;
    while (X[i] != '\0')
    {

        if (X[i] == '.') // if it sees a dot it will start countung the decimals
        {
            sawDot = true;
        }

        if (!sawDot && 48 <= X[i] && X[i] <= 57) //if sees a number before seeing
                                                 // a dot it will consider that number as a whole number
        {

            whole[j] = X[i];

            // printf("found a whole number and it is %d\n", whole[j]-48);
            j++;
        }
        else if (sawDot && 48 <= X[i] && X[i] <= 57) //if sees a number after seeing
                                                     // a dot it will consider that number as a decimal
        {
            decimal[I] = X[i];
            // printf("found a decimal and it is %d\n", decimal[I]-48);

            I++;
        }
        i++;
    }

    double x = MakeDouble(j, whole, I, decimal);

    return x;
}
//takes two arrays of intigers (or chars),one array showing the decimals and one array showing the whole numbers ,
// and produces a double
double MakeDouble(int j, int whole[], int i, int decimal[])
{

    double x;
    // printf("Make double is in place\n");

    for (int J = 0; J < j; J++)
    {
        x += (whole[J] - 48) * pow(10, j - J - 1);
    }
    for (int I = 0; I < i; I++)
    {
        x += 1.0 * (decimal[I] - 48) * pow(0.1, I + 1);
    }
    return x;
}