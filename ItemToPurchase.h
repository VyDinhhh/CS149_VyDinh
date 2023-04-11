#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

typedef struct ItemToPurchase_struct{ // Definition of ItemToPurchase struct
   char itemName[50]; // Name of the item, up to 50 characters
   int itemPrice; // Price of the item
   int itemQuantity; // Quantity of the item
}ItemToPurchase;

void MakeItemBlank(ItemToPurchase *item); // Function prototype for MakeItemBlank
void PrintItemCost(ItemToPurchase item); // Function prototype for PrintItemCost

#endif // End of header guard
