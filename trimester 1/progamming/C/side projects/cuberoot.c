#include <stdio.h>
#include <math.h>
double decimal(double n, double diff, double previous);
double cubeRoot(double n, int x);


int main()
{
   double n = 0, answer;
   int ashar;// ashar means decimal in Persian
   printf("please enter the number that you want the cube root of:");
   scanf("%lf", &n);
   printf("please enter the number decimal points(max 13)");
   scanf("%d", &ashar);
   if (n < 0)
   {
      answer = -cubeRoot(-n, ashar);
   }
   else if (n >= 0)
   {
      answer = cubeRoot(n, ashar);
   }

   printf("Cube root of %lf is %.13lf\n", n, answer);

   return 0;
}
double cubeRoot(double n, int ashar)
{
   double i = 0;
   while (pow(i,3)<= n)
   {
      i++;
   }
   i--;
   for (int j = 1; j <= ashar; j++)
   {
      i = decimal(n, pow(0.1, j), i);
   }

   return i;
}
double decimal(double n, double diff, double previous)
{
   while (pow(previous,3) < n)
   {
      previous += diff;
   }
   double answer= previous - diff;
   return answer;
}
