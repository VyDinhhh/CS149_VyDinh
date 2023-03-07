/**
 * Description: This program print the reverse 
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 3/5/2023
 * Creation date: 3/4/2023
 **/
#include <stdio.h>
#include <string.h>

int main(void) {

   /* Type your code here. */
   char str[50];
   
   //set stop to start the loop
   int stop =1;
   
   while(stop !=0){
   printf("Input string: ");
   fgets(str,50 , stdin);
   
   // set the last char to \0
   str[strlen(str)-1] = 0;
   if(strcmp(str,"Done")==0||strcmp(str,"done")==0||strcmp(str,"d")==0)
   {break;}
   
   // print in reverse
   for(int i=strlen(str)-1; i>=0;i--)
   {
      printf("%c",str[i]);
   }
   printf("\n");
   }

   return 0;
}

