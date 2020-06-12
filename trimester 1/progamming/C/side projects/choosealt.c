//choose function using loops
//
// by Mohammad Ali Agharazi
#include <stdio.h>
unsigned long long int choose(unsigned int n, unsigned int r);
int main(void){
    
    long int r,n;
    printf("what number's enter n in the form nCr:");
    scanf("%d", &n);
    printf("what number's enter r in the form nCr:");
    scanf("%d", &r);

    printf("%ldC%ld=%llu",n,r,choose(n,r));

    return 0;
}
unsigned long long int choose(unsigned int n, unsigned int r)
{
    long double answer=1;
    for (int i = 1; i <= r; i++)
    {
        answer*=1.0*n/i;
        // printf("%lf\n",answer);
        n--;
    }
    return answer;
    
}