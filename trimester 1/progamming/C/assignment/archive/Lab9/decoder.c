#include <stdio.h>

#define MAX 80
#define NUMBER_OF_ALPHABETS 26
int main() {
    //declaring our variables
    int i,j;
    int check;
    //declaring permutations
    char perm[] = "qjczieaungsdfxmphybklortvw";
    char permu[] = "QJCZIEAUNGSDFXMPHYBKLORTVW";

    //asking for an input
    char str [MAX];
    printf("please enter a string for us to decode:");
    fgets(str,MAX,stdin);

    for ( i = 0; i < MAX; i++)
    {
        check=0;// this is to make sure that the last letter wouldn't continue repeating

        //if (str[i]>96&&str[i]<123)//if its lower case
        //{
            for ( j = 0; j < NUMBER_OF_ALPHABETS; j++)
            {
                if (str[i]==perm[j])
                {
                   // check=1;
                    break;
                }
            }
       // }
        /*if (str[i]>=65&&str[i]<=90)//if its upper case
        {
            for ( j = 0; j < NUMBER_OF_ALPHABETS; j++)
            {
                if (str[i]==permu[j])
                {
                    check=2;
                    break;
                }
            }
        }*/
        
       // if (check==1)
      //  {
            str[i]=j+97; 
       /* } else if (check==2)
        {
            str[i]=j+65; 
        }*/
          
    }
    
    printf("%s\n",str);
    

    return 0;
}
