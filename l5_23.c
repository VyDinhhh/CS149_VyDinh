/**
 * Description: This program is to find 2 smallest number in a list
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 2/19/2023
 * Creation date: 2/15/2023
 **/
#include <stdio.h>

int main(void) {

   /* Type your code here. */
   int firstSmallest;
   int secondSmallest;
   int length;
   int numbers[20];
   
   printf("Enter a size of list: ");
   scanf("%d", &length);
   
   int n=0;
   printf("Enter numbers in list: ");
   while(n<length)
   {
      scanf("%d", &numbers[n]);
      n++;
   }
   
   firstSmallest=numbers[0];
   //secondSmallest=numbers[0];
   for(int i=1; i<length; i++)
   {
   	//if the fist number is the smallest number, assign the second smallest to the second number in list
      if(firstSmallest<numbers[i])
      {
         secondSmallest=numbers[1];
      }
      
      //check if it is smallest
      if(firstSmallest > numbers[i])
      {
         secondSmallest=firstSmallest;
         firstSmallest=numbers[i];
         
      }
      //check the second smallest
      else if(secondSmallest>numbers[i] && numbers[i]!=firstSmallest)
      {
         secondSmallest=numbers[i];
      }
      
   }
   
   printf("The smallest number: %d and second smallest number: %d\n", firstSmallest,secondSmallest);

   return 0;
}

