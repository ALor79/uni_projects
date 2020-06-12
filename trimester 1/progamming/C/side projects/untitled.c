#include<stdio.h>
int main (){
    int counter=0;
    for (int x = 1000; x <= 9999; x++)
    {
        // if (x%35!=0&&(x%5==0||x%7==0))
        if(x%5==0||x%7==0)
        {
            counter++;
        }
        
    }
    printf("\n%d\n",counter);
    

    return 0;
}
