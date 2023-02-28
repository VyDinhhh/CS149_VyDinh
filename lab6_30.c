/**
 * Description: This program finds the min and max numbers
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 2/27/2023
 * Creation date: 2/24/2023
 **/
#include <stdio.h>

//function find max 
int MaxNumber(int num1, int num2, int num3,int num4)
{
   int max1=num1>num2?num1:num2;
   int max2=num3>num4?num3:num4;
   
   int finalMax= max1>max2?max1:max2;
   return finalMax;
}
//function find min
int MinNumber(int num1, int num2, int num3, int num4)
{
   int min1=num1<num2?num1:num2;
   int min2=num3<num4?num3:num4;
   int finalMin= min1<min2?min1:min2;
   
   return finalMin;
}
int main(void) {

   /* Type your code here. Your code must call the function.  */

   int num1,num2,num3,num4;
   int max,min;
   printf("Enter number 1: ");
   scanf("%d",&num1);
   printf("Enter number 2: ");
   scanf("%d",&num2);
   printf("Enter number 3: ");
   scanf("%d",&num3);
   printf("Enter number 4: ");
   scanf("%d",&num4);
   
   max=MaxNumber(num1,num2,num3,num4);
   min=MinNumber(num1,num2,num3,num4);
   
   printf("Maximum is %d\n",max);
   printf("Minimum is %d\n", min);
   return 0;
}

