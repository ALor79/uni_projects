#include<stdio.h>
#define MAX_LENGTH 80
char convert (char s);
int main() {
    char str [MAX_LENGTH+1],c;
    int i=0;
    printf("Enter your string: ");
    //get each character in an array
    while (c!='\n'&&i<MAX_LENGTH)
    {
        c = getchar();
        str[i]=c;
        i++;
    }
    

    

    
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        //check if it is lowercase
        if (str[i]>=97 && str[i]<=122 )
        {
            str[i] -= 32;
        }//else do nothing
        
         
    }
    printf("%s \n",str);

    return 0;
}
