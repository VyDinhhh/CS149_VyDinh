/**
* Description: Math function
* Author name: Vy Dinh
* Author email: thithuyvy.dinh@sjsu.edu
* Last modified date: 02/12/2023
* Creation date: 02/9/2023
**/
#include <stdio.h>
#include <math.h>


int main(void) {
   double x;
   double y;
   double z;

  //printf("Enter a first number: ");
  scanf("%lf",&x);
   //printf("Enter a second number: ");
  scanf("%lf",&y);
   //printf("Enter a third number: ");
  scanf("%lf",&z);
  
  double x_power_of_z = pow(x,z);
  double x_power_of_ysqr = pow(x,pow(y,2));
  double abs_y = fabs(y);
  double sqrt_of_xy_toz= sqrt(pow(x*y,z));
  printf("%.2lf ", x_power_of_z);
  printf("%.2lf ", x_power_of_ysqr);
  printf("%.2lf ",abs_y);
  printf("%.2lf\n",sqrt_of_xy_toz);
   

   return 0;
}
