/**
 * Description: This program print out reverese binary
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 2/19/2023
 * Creation date: 2/15/2023
 **/
#include <stdio.h>

int main(void) {

   /* Type your code here. */
   int number;
   int reverse_binary[32];
   
   printf("Enter a positive integer: \n");
   scanf("%d",&number);
   
   int i=0;
   //do if the number is nonegative
   while(number>0)
   {
      reverse_binary[i]= number % 2;
      number = number/2;
      i++;
   }
   //print out the reverse binary
   printf("The reverse binary: ");
   for(int j=0; j<i; j++)
   {
      printf("%d", reverse_binary[j]);
   }
   printf("\n");
   return 0;
}

