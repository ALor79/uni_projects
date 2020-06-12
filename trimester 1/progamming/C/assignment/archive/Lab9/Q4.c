/*Write	a	program	to	count	the	number	of	characters	in	a	string.
(Remember	that	a	string	ends	when	the	’\0’ terminator	is	encountered,	
regardless	of	whether	any	other	characters	are	contained	in	the	array	
after	that	point.	If	the	null	terminator	is	not	encountered,	then	this	should	
be	reported	as	an	error).*/

#include <stdio.h>
// #include<stdbool.h>
#define MAX 100
int main()
{
    char string[MAX + 1];
    printf("enter a string:\n");
    fgets(string, MAX + 1, stdin);
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    printf("number of characters is %d", i - 1);

    return 0;
}