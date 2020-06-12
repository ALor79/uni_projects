 #include <stdio.h>
 #include<stdbool.h>

int main() {

    int i , temp, count=0,j,n;
    bool wasApplicable =false;
    //get n from the user
    printf("what's the length of the array?\n");
    scanf("%d",&n);
    int arr[n],half_n=n/2 ;

    //scanf all the values in array arr[]

    for (int k = 0; k < n; k++)
    {
        printf("enter a number for the %d th value",k+1);
        scanf("%d",&arr[k]);
    }
    


    //sort the array
for(i = 0; i<n-1; i++) {
    for(j = 0; j<n-1-i; j++) {
        if(arr[j] >arr[j+1]) {
            temp =arr[j];
           arr[j] =arr[j+1];
           arr[j+1] = temp;
        }
    }
}
//debug 1
// for (int k = 0; k < n; k++)
// {
//     printf ("%d \t",arr[k]);
// }
// printf("\n");

   // for everything in the array a[] check
   for(int k=0;k<n;k++)
    {
        if (arr[k+1]==arr[k])
        {
            count++;
            if (count+1>half_n) {
                printf ("%d was repeated more than %d times(which is half the length of the array)\n",arr[k],half_n);
                wasApplicable=true;
            }
        }
        else
        {
            // debug 2
            printf("%d was repeated %d times \n",arr[k],count+1);
            count=0;
        }
        
    }
    if (!wasApplicable)
    {
        printf("none of the numbers was repeated more than %d times/n", half_n);
    }
    
    
    return 0;
}