/*Write	a	program	to	read	an	integer	N and	write	out	the	base	2	
representation	of	N*/
#include<stdio.h>
int main() {
    printf("**************************binary convertor**************************\n");
    int arr[50];
    int i = 0;
    //ask the user for value
    int value;
    printf("please enter a natural number");
    scanf("%d",&value);

    while (value>0)
    {
        arr[i] = value%2;
        value = value/2;
        i++;
    }
    while (i > 0)
    {
       
        i--;
        printf("%d",arr[i]);
    }
    printf("\n");
    

    return 0;
}