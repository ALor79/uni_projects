// //Write	a	program	to	count	the	number	of	non-alphabetic	characters	in	a	
// string.	(An	alphabetic	character	is	any	of	the	characters:	
// ‘A’,’B’,…,’Z,‘a’,’b’,…,’z’)
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
        if (('A' >string[i] || string[i] > 'Z')&&('a' >string[i] || string[i] > 'z'))
        {
            count++;
        }

        i++;
    }
    printf("number of uppercase characters is %d", count-1);

    return 0;
}