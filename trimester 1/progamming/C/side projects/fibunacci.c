#include <stdio.h>
int Fib(int x);
int main()
{
    int x = 0;
    printf("what position of the fibonacci sequence do you want?\n");
    scanf("%d", &x);
    printf("The %d th number in the fibunacci sequence is %d\n", x, Fib(x));
    return 0;
}
int Fib(int x)
{
    if (x == 2 || x == 1)
        return 1;

    return Fib(x - 1) + Fib(x - 2);
}