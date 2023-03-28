/**
 * Description: This program count char in a string
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 3/27/2023
 * Creation date: 3/27/2023
 **/
 
 #include <stdio.h>
#include <string.h>

/* Define your function here */
int CalcNumCharacters(char* userString, char userChar)
{
   int count =0;
   // compare charracter
   for(int i=0; i<strlen(userString); i++)
   {
      
      if(userChar == userString[i])
      {
      	// count the exists of char
         count++;
      }
   }
   return count;
}
         

int main(void) {

   /* Type your code here. */
   char userString[50], userChar;
   scanf("%c %s",&userChar, userString);
   int count = CalcNumCharacters(userString, userChar);
   if(count>1)
      printf("%d %c's\n", count, userChar);
   else
      printf("%d %c\n", count, userChar);

   

   return 0;
}

