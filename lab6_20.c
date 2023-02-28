/**
 * Description: This program converts laps to miles
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 2/27/2023
 * Creation date: 2/24/2023
 **/
#include <stdio.h>
 double LapsToMiles( double userLaps)
{
   return userLaps*0.25;
}

int main(void) {

   /* Type your code here. Your code must call the function.  */
   double miles=0;
   double userLaps;
   printf("Enter laps: ");
   scanf("%lf",&userLaps);
   miles= LapsToMiles(userLaps);
   
   printf("%.2lf\n",miles);

   return 0;
}
