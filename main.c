/**
 * Description: This program is demonstrate a shopping cart
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 4/10/2023
 * Creation date: 4/8/2023
 **/
#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h" // Include the header file for the ItemToPurchase struct

int main(void) {

   char c;
   ItemToPurchase item1; // Declare an instance of the ItemToPurchase struct called item1
   ItemToPurchase item2; // Declare another instance of the ItemToPurchase struct called item2

   MakeItemBlank(&item1); // Call the MakeItemBlank function to set all members of item1 to blank values
   MakeItemBlank(&item2); // Call the MakeItemBlank function to set all members of item2 to blank values

   // Get input for item1
   printf("Item 1\n");
   printf("Enter the item name:\n");
   scanf("%[^\n]s",item1.itemName);
   printf("Enter the item price:\n");
   scanf("%d",&item1.itemPrice);
   printf("Enter the item quantity:\n");
   scanf("%d",&item1.itemQuantity);
   printf("\n");
   c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }

   // Get input for item2
   printf("Item 2\n");
   printf("Enter the item name:\n");
   scanf("%[^\n]s",item2.itemName);
   printf("Enter the item price:\n");
   scanf("%d",&item2.itemPrice);
   printf("Enter the item quantity:\n");
   scanf("%d",&item2.itemQuantity);
   printf("\n");

   // Print the total cost of each item and the overall total cost
   printf("TOTAL COST\n");
   PrintItemCost(item1);
   PrintItemCost(item2);
   printf("\nTotal: $%d\n", item1.itemPrice*item1.itemQuantity+item2.itemPrice*item2.itemQuantity);

   return 0;
}
