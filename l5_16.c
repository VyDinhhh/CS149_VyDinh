/**
 * Description: This program is to print the reverse of number in list
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 2/19/2023
 * Creation date: 2/15/2023
 **/
#include <stdio.h>

int main(void) {
   const int NUM_ELEMENTS = 20;         // Number of input integers
   int userVals[NUM_ELEMENTS];          // Array to hold the user's input integers

   /* Type your code here. */
   int i=0;
   //printf("Enter numbers: ");
   
   printf("Enter size of list and numbers in list: ");
   do{
   	if(i>NUM_ELEMENTS)
   	{break;}

      scanf("%d",&userVals[i]);
      i++;
   }while(i<=userVals[0]);
   //print reverse
   for(int j=i-1; j>0; j--)
   {
      printf("%d,", userVals[j]);
   }
   printf("\n");
   return 0;
}

