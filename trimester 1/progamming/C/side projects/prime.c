#include <stdio.h>
#include <math.h>
#define MAX_SIZE 2000
int main()
{
    int arr[MAX_SIZE];
    int length = 400;
    int M = 0;
    for (int i = 0; i < length - 1; i++)
    {
        arr[i] = i + 2;
    }
    int i = 0;
    while (i < length)
    {
        M = arr[i];
        for (int b = i + 1; b < length - 1; b++)
        {
            if (arr[b] % M == 0)
            {

                for (int j = b; j < length; j++)
                {
                    int temp;
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        i++;
    }
    i = 0;
    while (arr[i] != 4)
    {
        printf("%d\n", arr[i]);
        i++;
    }

    return 0;
}
