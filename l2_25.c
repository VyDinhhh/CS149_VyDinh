/**
* Description: Divide by x
* Author name: Vy Dinh
* Author email: thithuyvy.dinh@sjsu.edu
* Last modified date: 02/12/2023
* Creation date: 02/9/2023
**/
#include <stdio.h>

int main(void) {

  
   int userNum;
   int x;
   
   scanf("%d", &userNum);
   scanf("%d", &x);
   int firstNum = userNum/x;
   int secondNum = firstNum/x;
   int thirdNum = secondNum/x;
   printf("%d ", firstNum);
   printf("%d ", secondNum);
   printf("%d\n", thirdNum);
   
   //another way to solve
   // for(int i=0; i<3; i++)
   // {
   //    userNum/=x;
   //    printf("%d ", userNum);
   
   // }
   // printf("\n");
 

   return 0;
}
