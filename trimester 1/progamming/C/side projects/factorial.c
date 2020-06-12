//factorial using recursive functions
//
// by Mohammad Ali Agharazi
#include <stdio.h>
int fact(int n);
int main()
{
    int x;
    printf("what number's factorial do you want:");
    scanf("%d", &x);
    printf("The factorial of %d is %d\n", x, fact(x));
    return 0;
}
int fact(int x)
{
    if (x == 1)
        return 1;

    return x * fact(x - 1);
}