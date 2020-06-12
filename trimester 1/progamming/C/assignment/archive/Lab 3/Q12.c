#include <stdio.h>

int main(){
    int day, i;
    for (day=1;  day <= 3; day++)
    {
        printf("on the %d day of Christmas",day);
        printf("my true love gave to me \n");
        for (i=day; i >0; i--){
            if (i==1)
            {
                if(day == 1) {printf("A ");}
                else {printf("And a");}
                printf("partridge in a pear tree.\n");
            }
            else if (i==2)
            {
                printf("two turtledoves,\n");
            }
            else if (i==3)
            {
                printf("three French hens,\n");
            }
            else if (i==4)
            {
                printf("Four calling birds,\n");
            }
            else if (i==5)
            {
                printf("five golden rings,\n");
            }
            else if (i==6)
            {
                printf("Six geese a laying ,\n");
            }
            else if (i==7)
            {
                printf("Seven swans a swimming ,\n");
            }  
            else if (i==8)
            {
                printf("Eight maids a milking ,\n");
            }
            else if (i==9)
            {
                printf("Nine ladies dancing\n");
            }
            else if (i==10)
            {
                printf(" Ten lords a leaping");
            }
            else if (i==11)
            {
                printf("Eleven pipers piping,\n");
            }
            else if (i==12)
            {
                printf("three French hens,\n");
            }                                              
        }
       printf("\n"); 
    }
    return 0;
    
}