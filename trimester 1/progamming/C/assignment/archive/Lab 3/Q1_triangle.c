#include<stdio.h>
#include<math.h>
#include <string.h>
int main (){
    //making a new variable to find the height and base of the triangle
    float height ;
    printf ("what is the height of the triangle");
    scanf("%f", &height);
    float base ;    
    printf ("what is the base of the triangle");
    scanf("%f", &base);
    //calculating the area of triangle
    float area=0.5*height*base;
    //displaying the answer
    printf("%f", area);


    
    

    return 0;
}
