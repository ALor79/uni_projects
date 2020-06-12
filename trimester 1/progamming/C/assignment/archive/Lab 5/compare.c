/*Write	a	program	that	reads	four	floating	point	values	w,x,y,z and	
modifies	them	so	that	w now	contains	the	minimum	value,	x,	contains	the	
next	smallest	value,		y,	contains	the	next	smallest	value,	and	z contains	
the	maximum	value.*/
/*********************************************************************************************************************
 ****note: this program does not work with visual stodio code compiler please use an online compiler or a terminal****
 *********************************************************************************************************************/
#include<stdio.h>
int main() {
    //declaring veriables and array arr
    double arr[4];
    double PlaceHolder; 
    int i;
    int j;
    // asking the user for input
    for ( i = 0; i < 4; i++)
    {
        if (i==0)
        {
            //asking for the first input
        printf("please give us you first value and we will arrenge them");
        scanf("%lf",&arr[0]);
        }
        else
        {   //asking fir the rest of the inputs
            printf("please give us another value");
            scanf("%lf",&arr[i]);
        }
    }
//swaping the values
for (j = 0; j < 4; j++)
{
       
        for(i=j;i<4;i++)
        {
            if (arr[j]>arr[i])
            {
            PlaceHolder=arr[j];
            arr[j]=arr[i];
            arr[i]=PlaceHolder;
            }
               

            
        }
}
//displaying the ordered numbers
    for (i = 0; i < 4; i++)
    {
        printf("%.2lf\t",arr[i]);
    }
    

        
    return 0;
}//gcc compare.c -o compare.exe