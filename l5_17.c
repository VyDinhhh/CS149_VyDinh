/**
 * Description: This program is to find the middle item
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 2/19/2023
 * Creation date: 2/15/2023
 **/
#include <stdio.h>

int main(void) {
   const int NUM_ELEMENTS = 9;
   int userValues[NUM_ELEMENTS];    // Set of data specified by the user

   int i=0;
   printf("Enter number(negative number to exit): \n");
   do{
      scanf("%d", &userValues[i]);
      i++;
      
   }while(userValues[i-1]>=0);//exit if negative number
   
   int pos= ((i-1)/2);//position of middle value
   //printf("%d", pos);
      if(i>10)
      {
         printf("Too many numbers\n");
         
      }else{
         printf("Middle item: %d\n", userValues[pos]);
         }

   return 0;
}

