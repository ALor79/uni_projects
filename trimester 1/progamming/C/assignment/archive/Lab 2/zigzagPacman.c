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
    sx=9;
    sy=12;
    dx=3;
    dy=4;

    
   
    //defining diff_x and diff_y
    diff_x =dx-sx;

    diff_y =dy-sy;
    //defining the absolute value of diff_y and diff_x
    int absDiffX = sqrt(diff_x*diff_x);
    int absDiffY = sqrt(diff_y*diff_y);


   if (absDiffX >= absDiffY){
            
        if (diff_y >=0 && diff_x >= 0)
        {    

           for (int i = 0 ; i < absDiffY ;i++ )
           {
               R();
               w();
               L();
               w();
            }
            G(absDiffX-absDiffY);
        }
        else if (diff_y <0 && diff_x>0 )
        {    
               R() ;
               R() ;
           for (int i = 1 ; i < absDiffY ;i++ )
           {
               w();
               L();
               w();
               R();
            }
            L();
            int J=absDiffX-absDiffY+1;
             G(J);
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
        
             G(absDiffX-absDiffY-1);   
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

           for (int i = 0 ; i < absDiffX ;i++ )
           {
               L();
               w();
               R();
               w();
                   
            }

             G(absDiffY-absDiffX);
        }
        else if (diff_y <0 && 0<diff_x )
        {
              R() ;    
              R() ;
           for (int i = 0 ; i < absDiffX ;i++ )
           {
               w();
               L();
               w();
               R();    
            }
                 
             G(absDiffY-absDiffX);
        } 
        else if (diff_y < 0 && diff_x < 0)
        {
               L() ;
               L();
           for (int i = 0 ; i < absDiffX  ;i++ )
           {
               w();    
               R();
               w();
               L();
            }    
    
            G(absDiffY-absDiffX);   
        }    
        else
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
//gcc zigzagPacman.c -o zigzagPacman.exe