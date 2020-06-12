// Write	a	program	to	count	the	number	of	uppercase	characters	in	a	string.

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
        if ('A' <= string[i] && string[i] <= 'Z')
        {
            count++;
        }

        i++;
    }
    printf("number of uppercase characters is %d", count);

    return 0;
}