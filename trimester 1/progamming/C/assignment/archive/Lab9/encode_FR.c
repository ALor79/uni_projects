#include <stdio.h>
#define Far_A "\u0622"
#define Far_alf "\u0627"
#define Far_B "\u0628"
#define Far_P "\u067E"
#define Far_T "\u062A"
#define Far_th "\u062B"
#define Far_j "\u062C"
#define Far_ch "\u067E"
#define Far_h "\u067E"
#define Far_kh "\u067E"
#define MAX 80
int main() {
    int temp;
    char perm[] = {Far_A,Far_B,Far_P,Far_T,Far_th,Far_j,Far_ch,Far_h,Far_kh,'a','b','p','d','o','j','h','g','t','y','u','i','z','x','c','v'};
    
    char str [MAX];
    printf("please enter a string for us to encode:");
    fgets(str,MAX,stdin);
    for (int i = 0; i < MAX; i++)
    {
        if (str[i]>=97&& 122>=str[i])
        {
            temp =str[i]-97;
            str[i]= perm[temp];
        }else if (str[i]>=65&&90>=str[i])
        {
            temp =str[i]-65;
            str[i]= perm[temp];
        }
    }
    printf("%s\n",str);
    

    return 0;
}
