/*Write	a	program	to	reverse	a	string,	so	that	if		on	input
char msg[]=”Reverse me”
at	the	end	of	the	program	
msg[]=”em esreveR”*/
#include <stdio.h>
#define MAX 100
int main()
{
    char string[MAX + 1];
    fgets(string, MAX + 1, stdin);
    int i = 0, j ;
    char temp;
    while (string[i] != '\0')
    {
        i++;
    }
    printf("%d\n",i);
    for (j=0; j < i/2; j++)
    {
        
        temp=string[j];
        string[j]=string[i-j-1];
        string[i-j-1]=temp;
        
    }
    

    printf("the reverse is \n %s", string);

    return 0;
}