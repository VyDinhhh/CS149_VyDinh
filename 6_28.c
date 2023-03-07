/**
 * Description: This program print only aplabet string  
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 3/5/2023
 * Creation date: 3/4/2023
 **/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 
* Function remove the not alphabet character
* parameters: char, char
* return: nothing
*/
void RemoveNonAlpha(char userString[], char userStringAlphaOnly[])
{
   int pos=0;
   for(int i=0; i< strlen(userString); i++)
   {
      
      if((userString[i] >= 'a' && userString[i] <= 'z') || (userString[i] >= 'A' && userString[i] <= 'Z'))
      {
         userStringAlphaOnly[pos]=userString[i];
         pos++;
      }
   }
    userStringAlphaOnly[pos]='\0';
}
int main(void) {

   /* Type your code here. */
   char str[50];
   char strAlphaOnly[50];
   fgets(str, 50, stdin);
   // call function
   RemoveNonAlpha(str, strAlphaOnly);
   printf("%s\n", strAlphaOnly);

   return 0;
}

