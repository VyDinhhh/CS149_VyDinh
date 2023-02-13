/**
* Description: Real estate
* Author name: Vy Dinh
* Author email: thithuyvy.dinh@sjsu.edu
* Last modified date: 02/12/2023
* Creation date: 02/9/2023
**/
#include <stdio.h>

int main(void) {
   int currentPrice;
   int lastMonthsPrice;
   double monthlyMortgage;
   int change;
   
   scanf("%d", &currentPrice);
   scanf("%d", &lastMonthsPrice);
   
   monthlyMortgage = (currentPrice*0.051)/12;
   change=currentPrice-lastMonthsPrice;
   printf("This house is $%d. The change is $%d since last month.\n", currentPrice, change);
   printf("The estimated monthly mortgage is $%lf.\n",monthlyMortgage);

   return 0;
}
