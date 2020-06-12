// Write	a	program	to	remove	all	the	spaces	in	a	string	so	that	if	
// char msg[] = “Too many spaces”;
// it	is	modified	to	“Toomanyspaces”;
/*Write	a	program	to	count	the	number	of	punctuation	marks	in	a	string,	
where	a	punctuation	mark	is	any	character	in	the	string	“;.,:?”
.*/


/*Generalise	your program	so	that	the	user	can	input	any	substring	of	
characters,	and	it	counts	the	number	of	occurrences	of characters	from	
this	sub-string	in	a	message	string*/
#include <stdio.h>
#define MAX 100
int main()
{
    char string[MAX + 1],output[MAX+1];

    fgets(string, MAX + 1, stdin);
    int i = 0, j= 0;
    while (string[i] != '\0')
    {
        if (string[i]!=' ')
        {
    
            output[j]=string[i];
            j++;
        }else if (string[i]==' '&&string[i+1]!=' ')
        {
            output[j]=string[i];
            j++;
        }
        

        i++;
    }
    output[j]='\0';
    printf("without spaces the string is:\n%s", output);

    return 0;
}