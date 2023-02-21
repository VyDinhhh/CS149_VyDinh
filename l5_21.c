/**
 * Description: This program is to find the word contains character
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 2/19/2023
 * Creation date: 2/15/2023
 **/
#include <stdio.h>
#include <string.h>

int main(void) {

   /* Type your code here. */
   int number;
   char words[20][10];
   char letter;
   int n=0;
   printf("Enter size of the list: ");
   scanf("%d",&number);
   printf("Enter words in the list: ");
   while(n<number)
   {
      scanf("%s", words[n]);
      n++;
   }
   printf("Enter a character: ");
   scanf(" %c", &letter);
   //search for character in list
   for(int i=0; i<n;i++)
   {
      for(int j=0; j<strlen(words[i]); j++)
      {
         if(words[i][j]==letter)
         {
            printf("%s,",words[i]);
            break;
         }
      }
   }
   printf("\n");

   return 0;
}

