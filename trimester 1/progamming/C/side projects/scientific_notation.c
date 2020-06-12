#include<stdio.h>
int main() {
    double number ;

    scanf("%lf",&number);

    int power =0;
    

    while (number>=10 ||number<=-10 )
    {
        number/=10.0;
        power++;
  
    }
    while (number<1 &&number>-1)
    {
        number*=10.0;
        power--;
    }

    printf("%lf * 10 ^ %d\n", number, power);
    return 0;
}
//gcc scientific_notation.c -o scientific.exe