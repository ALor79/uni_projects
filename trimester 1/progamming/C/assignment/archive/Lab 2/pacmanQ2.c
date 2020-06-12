/*Change	the	source	and	destination	values.	Check	if	the	program	writes	out	a	
correct	set	of	steps.		What	happens	if	you	enter	negative	values	for	the	source	
or	destination?		What	happens	if	the	source	and	destination are	the	same*/


#include <stdio.h>
void Go(int steps);
int main(void)
{
    int sx,sy,dx,dy;
    int diff_x, diff_y;
    sx = 4;
    sy = 1;
    dx = -3;
    dy = -2;
    diff_x = dx - sx;
    diff_y = dy - sy;
    
    if (diff_x > 0 && diff_y > 0)
    {
        printf("Right \n");
        Go(diff_x);
        printf("Right \n");
        Go(diff_y);
    }

    else if (diff_x > 0 && diff_y < 0)
    {
        printf("Right \n");
        Go (diff_x);
        printf("Left \n");
        Go (-diff_y);

    }
    else if (diff_x < 0 && diff_y > 0)
    {
        printf ("Left \n") ;
        Go( - diff_x ) ;
        printf ("Left \n") ;
        Go( diff_y ) ;
        
    }
    else if (diff_x < 0 && diff_y < 0)
    {
        printf("Left \n");
        Go( - diff_x ) ;
        printf ("Right \n") ;
        Go( - diff_y ) ;
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