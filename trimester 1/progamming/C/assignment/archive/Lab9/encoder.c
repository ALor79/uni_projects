#include <stdio.h>
#define MAX 80
int main() {
    int temp;
    //permutations
    char perm[] = "qjczieaungsdfxmphybklortvw";
    char permu[] = "QJCZIEAUNGSDFXMPHYBKLORTVW";
    char str [MAX];
    //user input
    printf("please enter a string for us to encode:");
    fgets(str,MAX,stdin);
    //replacing letters
    for (int i = 0; i < MAX; i++)
    {
        if (str[i]>=97&& 122>=str[i])
        {
            temp =str[i]-97;
            str[i]= perm[temp];
        }else if (str[i]>=65&&90>=str[i])
        {
            temp =str[i]-65;
            str[i]= permu[temp];
        }
    }
    //displaying the encoded letter
    printf("%s\n",str);
    

    return 0;
}
