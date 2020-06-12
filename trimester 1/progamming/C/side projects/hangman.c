#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    //get the word
    bool notInWord;
    int length, i = 0, k, lives, invisible;
    printf("number of the letters\n");
    scanf("%d", &length);
    getchar();
    invisible = length;
    char word[length + 1], visibility[length + 1], guess, f;
    lives = length * 2;
    printf("enter the word\n");
    while (i < length + 1 && word[i] != '\n')
    {
        word[i] = getchar();
        i++;
    }

    word[length + 1] = '\0';
    // printf("%s",word);

    printf("\n\n\n\n\n\n\n\n\n\n");
    for (int j = 0; j < length; j++)
    {
        visibility[j] = '*';
    }
    // get an input
    printf("%s\n", visibility);
    
    while (lives != 0 && invisible != 0)
    {
        notInWord = true;
        printf("enter your guess\n");
        
        scanf("%c",&guess);
        getchar();
        if (guess != '\n')
        {
            
            // compare the input to all the values in the array
            for (k = 0; k < length + 1; k++)
            {

                if (guess == word[k])
                {
                    visibility[k] = word[k]; // if they are the same show the input
                    invisible--;
                    notInWord = false;
                }
                else if (notInWord == true)
                {
                    lives--;
                    printf("wrong answer ,you lost a life ,you have %d lives\n", lives); // if its wrong decrease the lives
                    notInWord = false;
                }
            }

            printf("%s\n", visibility);
        }
    }

    if (lives == 0) //if lives ==0 printf (you lost)
    {
        printf("no more lives left you lost");
    }
    else if (invisible == 0) //if invis ==0 printf (you won)
    {
        printf("you won,you saved a life today!!");
    }

    return 0;
}
