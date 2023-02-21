/**
 * Description: This program is to find number in range
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 2/19/2023
 * Creation date: 2/15/2023
 **/
#include <stdio.h>

int main(void) {

   /* Type your code here. */
   const int MAX=20;
   int n=0;
   //int limitNumber;
   int numbers[MAX];
   
   printf("Enter size of list and numbers in list: ");
   do{
      scanf("%d",&numbers[n]);
      n++;
   }while(n<=numbers[0]);
   
   int range[2];
   int i=0;
   printf("Enter start and end number of range: ");
   while(i<2)
   {
      scanf("%d",&range[i]);
      i++;
   }
   //sort the number in range
   for(int j=1; j<=numbers[0];j++)
   {
      if(numbers[j]>=range[0] && numbers[j]<=range[1])
      {
         printf("%d,",numbers[j]);
      }
   }
   printf("\n");
   

   return 0;
}

