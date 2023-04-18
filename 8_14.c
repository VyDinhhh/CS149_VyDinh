/**
 * Description: This program uses linklist to print names
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 4/10/2023
 * Creation date: 4/8/2023
 **/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ContactNode_struct {
   /* Define ContactNode struct here. */
   char contactName[50];
   char contactPhoneNumber[50];
   struct ContactNode_struct* nextNodePtr;

} ContactNode;

/* Define the functions here. */
void InitializeContactNode(ContactNode* thisNode, char name[], char p_number[], ContactNode* next)
{
   strcpy(thisNode->contactName, name);
   strcpy(thisNode->contactPhoneNumber, p_number);
   thisNode->nextNodePtr = next;
}

char* GetName(ContactNode* thisNode){
   return thisNode->contactName;
}

char* GetPhoneNumber(ContactNode* thisNode)
{
   return thisNode->contactPhoneNumber;
}

void InsertAfter(ContactNode* thisNode, ContactNode* newNode)
{
   ContactNode* tmpNext = NULL;
   tmpNext = thisNode->nextNodePtr;
   thisNode->nextNodePtr = newNode;
   newNode->nextNodePtr = tmpNext;
}

ContactNode* GetNext(ContactNode* thisNode)
{
   return thisNode->nextNodePtr;
}

void PrintContactNode(ContactNode* thisNode)
{
   printf("Name: %s\n",thisNode->contactName);
   printf("Phone: %s\n\n", thisNode->contactPhoneNumber);
}

int main(void) {
   /* Type your code here. */
   // Initialize head node
    ContactNode* headNode = NULL;

    // Read in the contact information for three people
    for (int i = 1; i <= 3; i++) {
        char name[50];
        char phone[50];

        // Read in name and phone number
        printf("Enter contact name for person %d:\n", i);
        fgets(name, 50, stdin);
        printf("Enter contact phone number for person %d:\n", i);
        fgets(phone, 50, stdin);

        // Remove newline characters from input
        name[strcspn(name, "\n")] = '\0';
        phone[strcspn(phone, "\n")] = '\0';

        // Create new node and initialize it with the input data
        ContactNode* newNode = malloc(sizeof(ContactNode));
        InitializeContactNode(newNode, name, phone, NULL);

        // Insert new node after head node
        if (i == 1) {
            headNode = newNode;
        } else {
            InsertAfter(headNode, newNode);
        }
    }
    printf("\n");

    // Output each contact
    for (int i = 1; i <= 3; i++) {
        ContactNode* thisNode = headNode;
        for (int j = 1; j < i; j++) {
            thisNode = GetNext(thisNode);
        }
        printf("Person %d: %s, %s\n", i, GetName(thisNode), GetPhoneNumber(thisNode));
    }

    // Output the linked list
    printf("\nCONTACT LIST:\n");
    ContactNode* currentNode = headNode;
    while (currentNode != NULL) {
        
        PrintContactNode(currentNode);
        currentNode = GetNext(currentNode);
        
    }


   return 0;
}
