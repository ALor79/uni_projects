/* Write	a	program	to	read	the	radius	of	a	sphere	and	display	the	volume.
The	formula	for	the	volume	of	a	sphere	is	[4/3	*	PI	*	(radius	*	radius	*	
radius)].*/
#include<stdio.h>
#include<math.h>

int main (){
    //making a new variable to hold the radius value
    float radius ;
    //asking the user for radius value
    printf ("what is the radius of the sphere?\n");
    scanf("%f", &radius);
    // difing pi
    float PI = M_PI;
    //calculating the volume of the sphere
    float volume=	(4.0/3.0)*PI*(radius*radius*radius);
    //displaying the answer
    printf("%.7f\n", volume);

    return 0;
}
//gcc Q4_sphere.c -o Q4.exe