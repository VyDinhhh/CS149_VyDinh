/**
 * Description: This program is to swap values  
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 3/19/2023
 * Creation date: 3/18/2023
 **/
#include <stdio.h>

/* Define your function here */ 
void SwapValues(int* userVal1, int* userVal2, int* userVal3, int* userVal4)
{
   int temp;
   temp = *userVal1;
   *userVal1 = *userVal2;
   *userVal2 = temp;
   temp = *userVal3;
   *userVal3 = *userVal4;
   *userVal4 = temp;
}

int main(void) {

   /* Type your code here. Your code must call the function.  */
   int val1, val2, val3, val4;
   printf("Enter val 1: ");
   scanf("%d", &val1);
   printf("Enter val 2: ");
   scanf("%d", &val2);
   printf("Enter val 3: ");
   scanf("%d", &val3);
   printf("Enter val 4: ");
   scanf("%d", &val4);
   
   SwapValues(&val1, &val2, &val3, &val4);
   
   printf("%d %d %d %d\n",val1,val2,val3,val4);

   return 0;
}
