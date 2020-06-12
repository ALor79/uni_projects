//in this version the user can delete any character or punctution that she/he wants
#include <stdio.h>
#define MAX 100 
#define length 10
int belongs(int punct_length,char punctarr[],char X);
int main(void) {
    char msg[MAX+1],output[MAX+1] ;
    char punct[length];
    int i, j=0;
    //emptying the strings
    for(int k = 0; k<=MAX ; k++)
    {
        msg[k]='\0';
        output[k]='\0';
    }

    for(int k = 0; k<=length ; k++)
    {
        punct[k]='\0';
    }
    //asking user from a input
    printf("enter a sentence\n");
    fgets(msg,MAX,stdin);
    printf("which punctutions do you want to remove(max 10 without spaces)");
    fgets(punct,length,stdin);

    
    for( i = 0; i < MAX; i++)
    {
        //checking if a char from msg belongs to punc
        if (!belongs(length,punct,msg[i])) {
            // if it doesn't belong put the char in output
            output[j]=msg[i];
            j++;
        }
        
        
    }
    //printing output
    printf("%s\n",output);
    
    return 0;
}
int belongs(int punct_length,char punctarr[],char X){
    
    for(int i = 0; i < punct_length; i++)
    {
        if (punctarr[i]==X) {
            return 1;
        }
          
    }
    return 0;

}