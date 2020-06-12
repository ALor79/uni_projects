#include <stdio.h>
#include <math.h>
int roundx(double k);
int main(void)
{
    double x =11.65,y=10.2;
    printf("x is %d and y is %d ",roundx(x),roundx(y));
    return 0;
}
int roundx(double x)
{
    if (x - floor(x) < 0.5)
    {
        return (int) x;
    }
    else
    {
        return (int) ceil(x);
    }
}