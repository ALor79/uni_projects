/*Rewrite	the	pacman	program	so	that	pacman	walks	up/down	before	he	
walks	left/right*/
#include <stdio.h>
void Go(int steps);
int main(void)
{
    int sx,sy,dx,dy;
    int diff_x, diff_y;
    sx = 4;
    sy = 1;
    dx = 5;
    dy = 5;
    diff_x = dx - sx;
    diff_y = dy - sy;
    if (diff_x > 0 && diff_y > 0)
    {
        printf("Right \n");
        printf("Right \n");
        Go(diff_y);
        printf("Left \n");
        Go(diff_x);
    }

    if (diff_x > 0 && diff_y < 0)
    {
        Go (-diff_y);
        printf("Right \n");
        Go (diff_x);

    }
    if (diff_x < 0 && diff_y > 0)
    {
        printf ("Left \n") ;
        printf ("Left \n") ;
        Go( diff_y) ;
        printf ("Right \n") ;
        Go( -diff_x ) ;
        
    }
    if (diff_x < 0 && diff_y < 0)
    {
        Go( - diff_y ) ;
        printf ("Left \n") ;
        Go( - diff_x ) ;
    }
    printf("\n");
    return 0;
}
void Go(int steps)
{
    int i;
    for(i=0;i<steps;i++)
        {
            printf("Walk a step \n");
        
        }
}