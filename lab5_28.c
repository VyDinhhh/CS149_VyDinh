/**
 * Description: This program check palindrome string  
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 3/12/2023
 * Creation date: 3/10/2023
 **/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {

   /* Type your code here. */
   char str[50];
   char temp[50];
   
   //user input
   printf("Enter palindrome string:");
   fgets(str, 50, stdin);
   int len = strlen(str);
   int j=0;
   
   //remove space in line
   for(int i=0; i<len;i++)
   {
      if(!isspace(str[i]))
      { 
         temp[j]=str[i];
         j++;
      }
   }
   //add to the end of string
   temp[j]='\0';
      
   len= strlen(temp);
   
   
   for(int i =0; i<len; i++)
   {
      //compare characters
      if(temp[i]!=temp[len-i-1])
      {
         printf("not a palindrome: %s\n", str);
         return 0;
      }
      //if the loop pass the middle, then break
      if(i>len/2+1)
      {break;}
      
   }
   
   
   printf("palindrome: %s\n", str);
   return 0;
}

