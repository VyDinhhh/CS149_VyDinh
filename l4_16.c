#include <stdio.h>

int main(void) {

   /* Type your code here. */
   
   int n=0;
   int numbers[50];
   
   printf("Enter positive numbers (negative to exit): ");
   do{
      scanf("%d",&numbers[n]);
      n++;
   }while(numbers[n-1]>=0);
   
   int max= numbers[0];
   int sum=numbers[0];
   for(int i=1; i<n-1; i++)
   {
   	//find max number
      if(numbers[i]>max)
      {
         max=numbers[i];
      }
      //calculate the sum of list number
      sum+=numbers[i];
   }
   float average = (float)sum/(n-1);
   printf("Max:%d and Average: %0.2lf\n", max, average);

   return 0;
}

