/*6. Write	a	program	to	read	the	height,	width	and	depth	of	a	box	and	display	
the	volume.	
The	formula	for	the	volume	of	a	Cube	is	[height	*	width	*	depth].*/
#include<stdio.h>
#include<math.h>

int main (){
    //making a new variable to hold the width value
    float width, depth ,height ;
    //asking the user for width value
    printf ("what is the width of the Cube?\n");
    scanf("%f", &width);
    //asking the user for depth value
    printf ("what is the depth of the Cube?\n");
    scanf("%f", &depth);
    //asking the user for height value
    printf ("what is the height of the Cube?\n");
    scanf("%f", &height);

    //calculating the volume of the Cube
    float volume=(width*depth*height);
    //displaying the answer
    printf("%.7f\n", volume);

    return 0;
}
//gcc Q6_Cube.c -o Q6.exe