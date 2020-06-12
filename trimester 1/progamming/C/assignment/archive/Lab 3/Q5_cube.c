/*Write	a	program	to	read	the	width	of	a	Cube	and	display	the	volume	
The	formula	for	the	volume	of	a	Cube	is	[width	* width	*	width]..*/
#include<stdio.h>
#include<math.h>

int main (){
    //making a new variable to hold the width value
    float width ;
    //asking the user for width value
    printf ("what is the width of the Cube?\n");
    scanf("%f", &width);

    //calculating the volume of the Cube
    float volume=(width*width*width);
    //displaying the answer
    printf("%.7f\n", volume);

    return 0;
}
//gcc Q5_cube.c -o Q5.exe