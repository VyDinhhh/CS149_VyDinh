/**
 * Description: This program print out the sorted array  
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 3/12/2023
 * Creation date: 3/10/2023
 **/
#include <stdio.h>

/* using bubble sort */
void SortArray( int sortingList[], int numVals)
{
   for (int i = 1; i < numVals; i++) {
        for (int j = 1; j < numVals - i; j++) {
            if (sortingList[j] < sortingList[j+1]) {
                int temp = sortingList[j];
                sortingList[j] = sortingList[j+1];
                sortingList[j+1] = temp;
            }
        }
    }
    //print the sorted array
    for (int i=1; i<numVals;i++)
    {
       printf("%d,", sortingList[i]);
    }
    printf("\n");
}
      
   
int main(void) {

    int arr[20];
    int i = 0;
    
    printf("Enter a list of integers:\n");
    
    // Read integers from input
    do{
       scanf("%d",&arr[i]);
       if(arr[0]>=20)
       {break;}
       i++;
    }while(i <= arr[0]);

   if(arr[0]>=20)
       {return 0;}
   //pass to array
   SortArray(arr, arr[0]+1);
   
   return 0;
}

