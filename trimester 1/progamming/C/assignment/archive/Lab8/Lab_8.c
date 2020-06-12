 #include <stdio.h>
 #include<stdbool.h>

int main() {

    int i , temp, count=0,j,n,t;
    bool wasApplicable =false;
    //get n from the user
    printf("what's the length of the array?\n");
    scanf("%d",&n);
    int arr[n],half_n=n/2 ;

    //scanf all the values in array arr[]

    for (int k = 0; k < n; k++)
    {
        if (k%10==0 && k%100!=10)
        {
            printf("enter a value for the %d st value",k+1);
            scanf("%d",&arr[k]);
        }
        else if (k%10==1 && k%100!=11)
        {
            printf("enter a value for the %d nd value",k+1);
            scanf("%d",&arr[k]);
        }
        else if (k%10==2 && k%100!=12)
        {
            printf("enter a value for the %d rd value",k+1);
            scanf("%d",&arr[k]);
        }
        else
        {
            printf("enter a value for the %d th value",k+1);
            scanf("%d",&arr[k]);
        }
        
        
        

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
   for(t=0;t<n;t++)
    {
        if (arr[t+1]==arr[t])
        {
            count++;
            if (count+1>half_n) {

                wasApplicable=true;

            }
        }
        else
        {
            // debug 2
            printf("%d was repeated %d times \n",arr[t],count+1);
            count=0;
        }
    
    }
    printf("_______________________________\n");
    if (!wasApplicable)
    {
        printf("none of the numbers was repeated more than %d times\n", half_n);
    }else
    {
        printf ("%d was repeated more than %d times(which is half the length of the array)\n",arr[t],half_n);
    }
    
    
    
    return 0;
}