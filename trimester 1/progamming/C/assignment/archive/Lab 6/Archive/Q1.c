/*Write	a	program	that	plays	ROCK,	PAPER,	SCISSORS (RPS) with	the	user.		
RPS	is	a	two-player	game in	which	each	player	simultaneously	chooses	
either	ROCK,	PAPER	or	SCISSORS.*/
#include<stdio.h>
#include<stdlib.h>
int main() {
    //making two variables to store the choices
    char comchoice,userChoice;
    //making varibles to keep the scores
    int userScore=0;
    int comScore=0;
    int total=0;
        //error checking
        while(userScore!=6 || comScore!=6||userChoice!='r'||userChoice!='s'||userChoice!='p'||total!=10)
        {
            printf("what is your choice?(r ,p or s)\n");
            userChoice = getchar();
            getchar();
            //randomizing computer's choice
            char options[3]={'r','p','s'};
            comchoice= options [rand()%3];
            printf("computer's choice is :%c\n",comchoice);
            switch (comchoice)
            {
                case 'r'://determining who wins if computer's choice is r
                    if (userChoice=='r')
                    {
                        printf("draw no one gets a point\n");
                    }else if (userChoice =='s')
                    {
                        printf(" you lost a point to the computer\n");
                        comScore++;
                        printf("your score is %d and computer's score is %d\n",userScore,comScore);
                    }else if (userChoice =='p')
                    {
                        printf(" you won \n");
                        userScore++;
                        printf("your score is %d and computer's score is %d \n",userScore,comScore);
                    }else
                    {
                        printf("give a correct value \n");
                    }

                    break;

                case 's'://determining who wins if computer's choice is s
                    if (userChoice=='r')
                    {
                        printf(" you won\n");
                        userScore++;
                        printf("your score is %d and computer's score is %d\n",userScore,comScore);
                    
                    }
                    else if (userChoice =='s')
                    {
                        printf("draw no one gets a point\n");
                    }
                    else if (userChoice =='p')
                    {
                        printf(" you lost a point to the computer\n");
                        comScore++;
                        printf("your score is %d and computer's score is %d\n",userScore,comScore);
                    }
                    else
                    {
                        printf("give a correct value \n");
                    }

                    break;

                case 'p'://determining who wins if computer's choice is p
                    if (userChoice=='r')
                    {
                        printf(" you lost a point to the computer\n");
                        comScore++;
                        printf("your score is %d and computer's score is %d\n",userScore,comScore);
                    }
                    else if (userChoice =='s')
                    {
                        printf(" you won\n");
                        userScore++;
                        printf("your score is %d and computer's score is %d\n",userScore,comScore);
                    }
                    else if (userChoice =='p')
                    {
                        printf("draw no one gets a point\n");
                    }
                    else
                    {
                        printf("\n");
                    }
                    break;

                default:
                    printf("give a correct value \n");
                    break;
                    }
                if (comScore==6)
                {
                    printf("oh man you lost\n");
                    break;
                }else if (userScore==6)
                {
                    printf("hooray you won\n");
                    break;
                }
                if (total==10)
                {
                    if (comScore>userScore)
                    {
                        printf("oh man you lost\n");
                    }
                    else 
                    {
                        printf("hooray you won\n");
                    }
                    break;
                }
                
                total++;
            }   

        
        
    return 0;
}
