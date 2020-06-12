#include <stdio.h>
double calculate_y(double x,double a,double b,double c);
int main() {
    
    double x=0,a=0,b =0,c =0;
    printf("enter x:");
    scanf("%lf",&x);
    printf("enter a:");
    scanf("%lf",&a);
    printf("enter b:");
    scanf("%lf",&b);
    printf("enter c:");
    scanf("%lf",&c);
    double y=calculate_y(x,a,b,c);
    printf("answer is %lf\n",y);
    return 0;
}
double calculate_y(double x,double a,double b,double c){
    double y=a*x*x+b*x+c;
    return y;

}