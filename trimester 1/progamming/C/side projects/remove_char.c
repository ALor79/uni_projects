#include <stdio.h>
#include <string.h>
#define SEN_SIZE=1000
void revomePunc(char string[]);
int main() {
    char string[]="i'm a great  person.;,";
    revomePunc(string);
    printf("%s",string);
    return 0;
}
void revomePunc(char string[]){
    char temp[strlen(string)+1];
    int i=0,j=0;
    while (string[j]!='\0'||string[i]!='\n')
    {
        if (string[j]>'a'&&string[j]<'z')
        {
            temp[i]=string[j];
            i++;
        }
        j++;
        
    }
    strcpy(string, temp);
    
    
}