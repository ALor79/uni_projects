#include <stdio.h>
#define MAX_SIZE 5000
#define CONSTANT 0.5 

int main(void)
{
    // declaring variable
    int i;
    int k ;
    double a[MAX_SIZE];
    double temp;
    //asking user for k
    printf("please enter a value for k\n");
    scanf("%d",&k);
//importing file floats
    FILE *fp;
    fp = fopen("floats.txt", "r");

    for (i = 0;i<MAX_SIZE;i++)
        {
            fscanf(fp, "%lf", &a[i]);

        }
    fclose(fp);
    

//sorting the input array
for(int j=0;j<MAX_SIZE;j++)
{

    for (int i = 0; i < j; i++)
    {
        if (a[i]>a[j])
        {
            temp = a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    
    
}


if (a[MAX_SIZE-k-1]<CONSTANT)   //determining if the value is greater than 0.5
{
    printf("the value of the %dth largest value is less than the constant  ", k );
}
else
{   
    //displaying the value
    if (k==1)
    {
        printf("The largest value in the array that is larger than %lf and it is %lf\n", CONSTANT,a[MAX_SIZE-k-1]);
    }
    else if (k%10==1 && k%100!=11)
    {
        printf("The %dst largest value in the array that is larger than %lf and it is %lf\n", k,CONSTANT,a[MAX_SIZE-k-1]);
    }
    else if (k%10==2 && k%100!=12)
    {
        printf("The %dnd largest value in the array that is larger than %lf and it is %lf\n", k,CONSTANT,a[MAX_SIZE-k-1]);
    }
    else
    {
        printf("The %dth largest value in the array that is larger than %lf and it is %lf\n", k,CONSTANT,a[MAX_SIZE-k-1]);
    }
    
}

}
//gcc Q1.c o- Q1.exe