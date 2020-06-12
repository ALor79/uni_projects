#include <stdio.h>
#define MAX 100 
int main(void) {
    char msg[MAX+1],output[MAX+1];
    int i, j=0;
    //emptying the string
    for(int k = 0; k<=MAX ; k++)
    {
        msg[k]='\0';
    }
    printf("enter a sentence\n");
    fgets(msg,MAX,stdin);


    
    for( i = 0; i < MAX; i++)
    {
        
        if (msg[i]!='!'&&msg[i]!='?'&&msg[i]!='.'&&msg[i]!=','&&msg[i]!=';'&&msg[i]!=':'&&msg[i]!='\'') {
            output[j]=msg[i];
            j++;
        }
        
        
    }
    printf("%s\n",output);
    
    return 0;
}
