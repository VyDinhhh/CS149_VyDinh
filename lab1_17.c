/**
* Description: Program print the arrow with two input
* Author name: Vy Dinh
* Author email: thithuyvy.dinh@sjsu.edu
* Last modified date: 01/30/2023
* Creation date: 02/2/2023
**/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
   int baseInt;
   int headInt;
   
   
  
   int height=3;
   int width=4;
   
   /*prompt user input*/
   scanf("%d",&baseInt);
   scanf("%d",&headInt);
   
   for(int i=-height; i<=height; i++)
   {
      /*print out the head of the arrow*/
      if(abs(i)<height-1){
      for(int j=0;j<width;j++){
         
      // printf("%d",baseInt);
      printf("%d",baseInt);}
      for(int x=height-abs(i)+1;x>0;x--){
      printf("%d",headInt);}
      }else 
      {
      	/* print the base of the arrow*/
          for(int j=0;j<width;j++){
            
            printf(" ");}
            for(int x=height-abs(i)+1;x>0;x--){
      printf("%d",headInt);}
      }
      
      printf("\n");
   }
   return 0;
  }
