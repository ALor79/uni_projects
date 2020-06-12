/*Rewrite	the	pacman	program	so	that	pacman	walks	zig-zag	to	the	destination	
e.g.	one	step	left,	followed	by	one	step	up,	followed	by	one	step	left,	followed	
by	one	step	up	and	so	on.		(This	is	not	easy	for	novice	programmers	– do	not	
worry	if	you	cannot	do	this	question	at	this	stage.)*/
//the pacman is walking on a coordinate plain
#include<stdio.h>
#include<math.h>

void w (){
//walk one step
printf("Walk\n");
}
void G (int X){
for (int i = 0; i < X; i++)
{
w();
}
}
void L (){
// Turn left
printf("Left\n");
}
void R (){
// Turn right
printf("Right\n");
}

int main (){

    int diff_x, diff_y;
    int sy,sx,dx,dy;
    //asking for user's inpiut for starting coordinates    
    printf ("what is the value of Starting x");
    scanf ("%d", &sx);
    printf ("what is the value of Starting y");
    scanf ("%d", &sy);
    //asking for user's inpiut for coordinates of the destination 
    printf ("what is the final value of x");
    scanf ("%d" ,&dx);
    printf ("what is the final value of y");
    scanf ("%d" ,&dy);
    
   
    //defining diff_x and diff_y
    diff_x =dx-sx;
    diff_y =dy-sy;
    //defining the absolute value of diff_y and diff_x
    int absDiffX = sqrt(diff_x*diff_x);
    int absDiffY = sqrt(diff_y*diff_y);

   if (absDiffX > absDiffY){
        
        if (diff_y >=0 && diff_x >= 0)
        {
             R() ;
             w() ;
           for (int i = 0 ; i < absDiffY ;i++ )
           {
               L();
               w();
               R();
               w();
            }
             G(absDiffX-absDiffY);
        }
        else if (diff_y <0 && diff_x>0 )
        {
              R() ;
              w() ;
           for (int i = 0 ; i < absDiffY ;i++ )
           {
               R();
               w();
               L();
               w();
            }
                L();
             G(absDiffX-absDiffY);
        } 
        else if (diff_y < 0 && diff_x < 0)
        {
              L() ;
              w() ;
           for (int i = 0 ; i < absDiffY ;i++ )
           {
               L();
               w();
               R();
               w();
            }
                R();
             G(absDiffX-absDiffY);   
        }else
        {

           for (int i = 0 ; i < absDiffY ;i++ )
           {
               L();
               w();
               R();
               w();
            }
               L();
             G(absDiffX-absDiffY);   
        }
        

        

    }
    if (absDiffX < absDiffY){
        
        if (diff_y >=0 && diff_x >= 0)
        {
             R() ;
             w() ;
           for (int i = 0 ; i < absDiffX ;i++ )
           {
               L();
               w();
               R();
               w();
            }
             L();
             G(absDiffY-absDiffX);
        }
        else if (diff_y <0 && 0<diff_x )
        {
              R() ;
              w() ;
           for (int i = 0 ; i < absDiffX ;i++ )
           {
               R();
               w();
               L();
               w();
            }
             R();
             G(absDiffY-absDiffX);
        } 
        else if (diff_y < 0 && diff_x < 0)
        {
              L() ;
              w() ;
           for (int i = 0 ; i < absDiffX  ;i++ )
           {
               L();
               w();
               R();
               w();
            }
             L();
             G(absDiffY-absDiffX);   
        }else
        {

           for (int i = 0 ; i < absDiffX ;i++ )
           {
               L();
               w();
               R();
               w();
                }
            
             G(absDiffY-absDiffX);   
        }
        

        

    }
    
    return 0;
}
