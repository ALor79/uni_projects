#include<stdio.h>
int main (){
    //writing a text once
    printf(" Hello  World \n");
    //writing a string multiple times
    for (size_t i = 0; i < 5; i++)
    {
        printf("Hello Ireland \n ") /* \n means nextline */;
    }
    float f = 79.0;
    ++f;
     printf("\f", f);
    return 0;
}
