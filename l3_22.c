/**
* Description: Smallest number
* Author name: Vy Dinh
* Author email: thithuyvy.dinh@sjsu.edu
* Last modified date: 02/12/2023
* Creation date: 02/9/2023
**/
#include <stdio.h>

int main(void) {

   
   int x,y,z;
 
   scanf("%d %d %d",&x,&y,&z);
	if(x < y && x < z)
	{
		printf("%d\n",x);
	}
	else if(y < z)
	{
		printf("%d\n",y);
	}
	else
	{
		printf("%d\n",z);
	}	
   

   return 0;
}
