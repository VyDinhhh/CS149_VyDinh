/**
 * Description: This program is to find the number in range
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 2/19/2023
 * Creation date: 2/15/2023
 **/
#include <stdio.h>

int main(void) {
   const int NUM_ELEMENTS = 20;
   int userValues[NUM_ELEMENTS];    // Set of data specified by the user
   int i=0;
   /* Type your code here. */
   printf("Enter size of list and numbers in list: ");
   do{
   	if(i>NUM_ELEMENTS)
   	{break;}

      scanf("%d",&userValues[i]);
      i++;
   }while(i<=userValues[0]+1);
   
   for(int j=1; j<i-1; j++)
   {
   	//compare value with the last in list
      if(userValues[j]<userValues[i-1])
      {
         printf("%d,",userValues[j]);
      }
   }
      printf("\n");
   return 0;
}

