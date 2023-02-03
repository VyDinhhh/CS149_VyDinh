#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
   int baseInt;
   int headInt;
   
   
  
   int height=3;
   int width=4;
   

   scanf("%d",&baseInt);
   scanf("%d",&headInt);
   for(int i=-height; i<=height; i++)
   {
      if(abs(i)<height-1){
      for(int j=0;j<width;j++){
         
      // printf("%d",baseInt);
      printf("%d",baseInt);}
      for(int x=height-abs(i)+1;x>0;x--){
      printf("%d",headInt);}
      }else 
      {
          for(int j=0;j<width;j++){
         
            printf(" ");}
            for(int x=height-abs(i)+1;x>0;x--){
      printf("%d",headInt);}
      }
      
      printf("\n");
   }
   return 0;
  }
