/*Carefully	type	the	pacman	program	from	Lecture	2	into	an	editor.	Do	not	
copy	and	paste	– the	point	is	to	give	you	practice with	carefully	writing	C	
syntax.	Save,	compile	and	run	when	compilation	errors	have	been	removed.*/
#include <stdio.h>
void Go(int steps);
int main(void)
{
    int sx,sy,dx,dy;
    int diff_x, diff_y;
    sx = 10;
    sy = 7;
    dx = 4;
    dy = 12;
    diff_x = dx - sx;
    diff_y = dy - sy;
    if (diff_x > 0 && diff_y > 0)
    {
        printf("Right \n");
        Go(diff_x);
        printf("Lefr \n");
        Go(diff_y);
    }

    if (diff_x > 0 && diff_y < 0)
    {
        printf("Left \n");
        Go (diff_x);
        printf("Left \n");
        Go (-diff_y);

    }
    if (diff_x < 0 && diff_y > 0)
    {
        printf ("Left \n") ;
        Go( - diff_x ) ;
        printf ("Right \n") ;
        Go( diff_y ) ;
        
    }
    if (diff_x < 0 && diff_y < 0)
    {
        printf("Right \n");
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
            printf("Walk\n");
        
        }
}