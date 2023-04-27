
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CommandNodeLL.h"
/**
*CommandNode.c
*Author: Bill Andreopoulos
*The function bodies for a linked list of commands
*CS149 assignments 3-5 usage only
**/

void CreateCommandNode(CommandNode* thisNode, char cmd[20][20], int ind,int totalCommand,
CommandNode* nextCmd) {
//this is useful if you store a string (char *): strcpy(thisNode->command, cmd);
for (int i = 0; i < totalCommand; i++){
strcpy(thisNode->command[i],cmd[i]);}
thisNode->index = ind;
thisNode->nextCommandPtr = nextCmd;
return;
}
//insert node newNode after thisNode
void InsertCommandAfter(CommandNode* thisNode, CommandNode* newNode) {
CommandNode* tmpNext = NULL;
tmpNext = thisNode->nextCommandPtr;
thisNode->nextCommandPtr = newNode;
newNode->nextCommandPtr = tmpNext;
return;
}
//get next command node in linked list
CommandNode* GetNextCommand(CommandNode* thisNode) {
return thisNode->nextCommandPtr;
}
//find a command based on the pid
CommandNode* FindCommand(CommandNode* cmd, int pid) {
CommandNode* tmpNext = cmd;
while (tmpNext != NULL) {
if (tmpNext->PID == pid) { return tmpNext; }
tmpNext = tmpNext->nextCommandPtr;
}
return NULL;
}

