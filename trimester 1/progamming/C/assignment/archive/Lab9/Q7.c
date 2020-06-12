/*Write	a	program	to	count	the	number	of	punctuation	marks	in	a	string,	
where	a	punctuation	mark	is	any	character	in	the	string	“;.,:?”
.*/


/*Generalise	your program	so	that	the	user	can	input	any	substring	of	
characters,	and	it	counts	the	number	of	occurrences	of characters	from	
this	sub-string	in	a	message	string*/
#include <stdio.h>
// #include<stdbool.h>
#define MAX 100
int main()
{
    char string[MAX + 1];
    fgets(string, MAX + 1, stdin);
    int i = 0, count = 0;
    while (string[i] != '\0')
    {
        if (string[i]==':'||string[i]==';'||string[i]=='.'||string[i]==','||string[i]=='?')
        {
            count++;
        }

        i++;
    }
    printf("number of uppercase characters is %d", count);

    return 0;
}