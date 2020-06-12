#include<stdio.h>
//#nclude<stdbool.h>
#define MAX 100
int main(void)
{
    char msg[MAX];
    
    int i=0, k=MAX;
    int count=1;
    //set all the values to null to simplify the do-while loop later on
    for(int j = 0; j<=MAX ; j++)
    {
        msg[j]='\0';
    }
    printf("give sentence\n");
    fgets(msg,MAX,stdin);
    //ignores all the spaces from the beginning
    while (msg[i]==' '||msg[i]=='\t')
    {   
        i++;
        if (msg[i]!=' '&&msg[i]!='\t')
        {
        break;               
        }
        
    }
    //removes all the spaces from the end
    while (msg[k]==' '||msg[k]=='\t')
    {   
        msg[k]='\0';
        k--;
        if (msg[k]!=' '&&msg[k]!='\t')
        {
        break;               
        }
        
    }

    //this do-while loop does the counting
    do
    {
        
        
        if ((msg[i]==' '||msg[i]=='\t') && (msg[i+1]!=' ' &&msg[i+1]!='\t'/*&& msg[i+1]!='\0'*/)) {
            count++;
        }
        i++;
        
    } while (msg[i]!='\0'&& i<MAX);
    printf("there are %d words in this sentence",count);
    
    return 0;
}
//gcc Q1.c o- 1.exe
//this program does 200 iterations at most