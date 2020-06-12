#include <stdio.h>
#include <math.h>

void REF(int i, int j, double m[i][j]);
int main()
{
    int n, columns, rows;

    printf("how many rows does the matrix have");
    scanf("%d", &columns);
    printf("how many rows does the matrix have");
    scanf("%d", &rows);

    double Matrix[rows][columns];
    printf("enter the numbers in order with an enter after each one");

    //Taking user input for 2D array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            scanf("%lf", &Matrix[i][j]);
        }
    }
    REF(columns, rows, Matrix);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%lf", Matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
void REF(int I, int J, double a[I][J])
{
    for (int i = 1; i < I; i++)
    {
        if (a[i][0] != 0)
        {
            for (int j = i; j < J; j++)
            {
                a[i][j] -= a[0][j] * a[i][j];
            }
        }
    }
}