#include<stdio.h>
#include<math.h>
#include <string.h>
void lower_string(char s[]) {
   int c = 0;
   
   while (s[c] != '\0') {
      if (s[c] >= 'A' && s[c] <= 'Z') {
         s[c] = s[c] + 32;
      }
      c++;
   }
}
int main (){



    //making a new variable to find if the user is giving € or £
    char answer [10];

    printf ("what do you want to convert £ or € (write pound or euro or sterling it is not case sensative)");

    scanf("%s",&answer);

    //lower case the string in case the user used a capital letter in their answer
    lower_string(answer);


    //see if the user has chosen euro or sterling
    
    if (answer == 'euro')
    {   
        // define a veriable and assign the number of euros the user wants to convert
        float Euros;
        printf ("how many euros?");
        scanf("%f",&Euros );
        //convert Euros to Sterling
        float InSterling =Euros/0.8 ;
        //display the answer
        printf("%f euros it is equal to %f sterlings" , Euros, InSterling);

    }
    else if (answer == 'pound' || answer == 'sterling' )
    {   
        // define a veriable and assign the number of Sterlings the user wants to convert
        float Sterlings;
        printf ( "how many Sterlings?");
        scanf("%f",&Sterlings );
        //convert Sterling to Euro
        float InEuro = Sterlings*0.8 ;
        //display the answer
        printf("%f Sterlings it is equal to %f euros" , Sterlings, InEuro);

        
    }
    
    

    return 0;
}
