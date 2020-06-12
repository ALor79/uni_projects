#include<stdio.h>
#include<math.h>



int main (void){

    
    //making a new variable to find if the user is giving € or £
    char answer ;
    

    
    //this if statement is used to determine if the user has entered the right format

    
    while(answer != 'E' ||answer != 'e' || answer != 'p' || answer != 'S'|| answer != 's' || answer != 'P'){
        printf ("what do you want to convert £ or € (write E or e for euro and S ,P ,p or s for sterling )\n");
        scanf("%c",&answer);


        //see if the user has chosen euro or sterling
    if (answer == 'E' ||answer == 'e')
    {   
        // define a veriable and assign the number of euros the user wants to convert
        double Euros;
        printf ("\nhow many euros?\n");
        scanf("%lf",&Euros );
        //convert Euros to Sterling
        double InSterling =Euros*0.8 ;
        //display the answer
        printf("%lf euros it is equal to %lf sterlings\n" , Euros, InSterling);
        break;

    }
    else if (answer == 'p' || answer == 'S'|| answer == 's' || answer == 'P' )
    {   
        // define a veriable and assign the number of Sterlings the user wants to convert
        double Sterlings;
        printf ( "How many Sterlings?");
        scanf("%lf",&Sterlings );
        //convert Sterling to Euro
        double InEuro = Sterlings/0.8 ;
        //display the answer
        printf("%lf Sterlings it is equal to %lf euros\n" , Sterlings, InEuro);
        break;
        }else
        {   getchar();
            printf("wrong format,please try again\n");
        }
        
    

    }
        


    return 0;
}
//gcc Q3_Euro_Sterling.c -o Q3.exe