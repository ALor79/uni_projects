/*Write	a	program	to	read	the	radius	of	a	circle	and	display the	area.
The	formula	for	the	area	of	a	circle	is	[PI	*	(radius	*	radius)*/
#include<stdio.h>
#include<math.h>

int main (){
    //making a new variable to hold the radius value
    float radius ;
    //asking the user for radius value
    printf ("what is the radius of the circle?\n");
    scanf("%f", &radius);
 
    float PI = M_PI;
    //calculating the area of the circle
    float area=	PI*	(radius	*	radius);
    //displaying the answer
    printf("%.8f\n", area);


    
    

    return 0;
}
//gcc Q2_circle.c -o Q2.exe