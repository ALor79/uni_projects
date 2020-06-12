//choose function using recursive functions
//
// by Mohammad Ali Agharazi
#include <stdio.h>
unsigned long long int choose(int n, int r);
unsigned long long int fact(unsigned int x);
int main()
{
    int n, r;
    printf("what number's enter n in the form nCr:");
    scanf("%d", &n);
    printf("what number's enter r in the form nCr:");
    scanf("%d", &r);
    printf("%d choose %d is %llu \n", n, r, choose(n, r));
    return 0;
}
unsigned long long int fact(unsigned int x)
{
    if (x == 1)
        return 1;

    return x * fact(x - 1);
}
unsigned long long int choose(int n, int r)
{
    return fact(n) / (fact(n - r) * fact(r));
}
