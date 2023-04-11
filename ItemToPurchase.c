#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h"

/* Type your code here */

// This function sets all members of an ItemToPurchase struct to blank values
void MakeItemBlank (ItemToPurchase *item)
{
   strcpy((*item).itemName,"none"); // Set the itemName member to "none"
   (*item).itemPrice = 0; // Set the itemPrice member to 0
   (*item).itemQuantity=0; // Set the itemQuantity member to 0
}

// This function prints the cost of an ItemToPurchase struct
void PrintItemCost( ItemToPurchase item)
{
   printf("%s %d @ $%d = $%d\n", item.itemName,item.itemQuantity, item.itemPrice, item.itemPrice*item.itemQuantity);
   // Print the item name, quantity, price, and total cost using the given format string
}

