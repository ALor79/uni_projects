#include<stdio.h>
#include<math.h>
int main (){
    //defining our varialble (delta is the Discriminant)
    float a,c,b,delta;
    float X1,X2;
    // asking the user for input
    printf("Enter a value for a\n");
    scanf("%f",&a);
    printf("Enter a value for b\n");
    scanf("%f",&b);
    printf("Enter a value for c\n");
    scanf("%f",&c);
    //calculating delta
    delta=b*b-4.0*a*c;
    //calculating the roots
    X1 = (-b+sqrt(delta))/(2.0*a);
    X2 = (-b-sqrt(delta))/(2.0*a);
    //testing cases for diffrent possible out comes
    if (a == 0) 
    {
        printf("invalid input a must be greater than 0\n");
    }
    
    if (delta <0 )
    {
        printf("there isn't a real root\n");
    }
    else if ( delta==0 )
    {
        printf("there is only one real root and it is equal to %f\n" ,X2);

    }
    else
    {
        printf("there are two real root and they are %f , %f\n " ,X2,X1);
    }
    


    return 0;
}//gcc Quad.c -o Quad.exe