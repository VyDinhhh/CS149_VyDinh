/**
 * Description: This program implements a simple memory tracer. It tracks the memory allocation and deallocation by using two functions MALLOC and REALLOC.
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 4/10/2023
 * Creation date: 4/5/2023
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>



struct TRACE_NODE_STRUCT {
  char* functionid;                // ptr to function identifier (a function name)
  struct TRACE_NODE_STRUCT* next;  // ptr to next frama
};
typedef struct TRACE_NODE_STRUCT TRACE_NODE;
static TRACE_NODE* TRACE_TOP = NULL;       // ptr to the top of the stack

/* function PUSH_TRACE */
/*
 * The purpose of this stack is to trace the sequence of function calls
**/
void PUSH_TRACE(char* p)          // push p on the stack
{
  TRACE_NODE* tnode;
  static char glob[]="global";

  if (TRACE_TOP==NULL) {

    // initialize the stack with "global" identifier
    TRACE_TOP=(TRACE_NODE*) malloc(sizeof(TRACE_NODE));

    // no recovery needed if allocation failed, this is only
    // used in debugging, not in production
    if (TRACE_TOP==NULL) {
      printf("PUSH_TRACE: memory allocation error\n");
      exit(1);
    }

    TRACE_TOP->functionid = glob;
    TRACE_TOP->next=NULL;
  }//if

  // create the node for p
  tnode = (TRACE_NODE*) malloc(sizeof(TRACE_NODE));

  // no recovery needed if allocation failed, this is only
  // used in debugging, not in production
  if (tnode==NULL) {
    printf("PUSH_TRACE: memory allocation error\n");
    exit(1);
  }//if

  tnode->functionid=p;
  tnode->next = TRACE_TOP;  // insert fnode as the first in the list
  TRACE_TOP=tnode;          // point TRACE_TOP to the first node

}/*end PUSH_TRACE*/

/* --------------------------------*/
/* function POP_TRACE */
/* Pop a function call from the stack */
void POP_TRACE()    // remove the op of the stack
{
  TRACE_NODE* tnode;
  tnode = TRACE_TOP;
  TRACE_TOP = tnode->next;
  free(tnode);

}/*end POP_TRACE*/



/* ---------------------------------------------- */
/* function PRINT_TRACE prints out the sequence of function calls that are on the stack at this instance */
/* Printing the function call sequence the other way around is also ok: funcC:funcB:funcA:global */
char* PRINT_TRACE()
{
  int depth = 50; //A max of 50 levels in the stack will be combined in a string for printing out.
  int i, length, j;
  TRACE_NODE* tnode;
  static char buf[100];

  if (TRACE_TOP==NULL) {     // stack not initialized yet, so we are
    strcpy(buf,"global");   // still in the `global' area
    return buf;
  }

  /* peek at the depth(50) top entries on the stack, but do not
     go over 100 chars and do not go over the bottom of the
     stack */

  sprintf(buf,"%s",TRACE_TOP->functionid);
  length = strlen(buf);                  // length of the string so far
  for(i=1, tnode=TRACE_TOP->next;
                        tnode!=NULL && i < depth;
                                  i++,tnode=tnode->next) {
    j = strlen(tnode->functionid);             // length of what we want to add
    if (length+j+1 < 100) {              // total length is ok
      sprintf(buf+length,":%s",tnode->functionid);
      length += j+1;
    }else                                // it would be too long
      break;
  }
  return buf;
} /*end PRINT_TRACE*/

// -----------------------------------------
// function REALLOC calls realloc
// For instance, example of print out:
// "File mem_tracer.c, line X, function F reallocated the memory segment at address A to a new size S"
// Information about the function F should be printed by printing the stack (use PRINT_TRACE)
void* REALLOC(void* p,int t,char* file,int line)
{
	p = realloc(p,t);
	fprintf(stdout, "File %s, line %d, function %s, segment reallocated to address %p to a new size %d \n", file, line, PRINT_TRACE(),p,t);
	return p;
}

// -------------------------------------------
// function MALLOC calls malloc
void* MALLOC(int t,char* file,int line)
{
	void* p;
	p = malloc(t);
	fprintf(stdout, "File %s, line %d, function %s, segment at address %p allocated to size %d\n", file, line, PRINT_TRACE(),p,t);
	return p;
}

// ----------------------------------------------
// function FREE calls free
void FREE(void* p,char* file,int line)
{
	free(p);
	fprintf(stdout, "File %s, line %d, function %s, segment at address %p deallocated\n", file, line, PRINT_TRACE(),p);
}

#define realloc(a,b) REALLOC(a,b,__FILE__,__LINE__)
#define malloc(a) MALLOC(a,__FILE__,__LINE__)
#define free(a) FREE(a,__FILE__,__LINE__)



// linklist to store commands from stdin
struct CommandNodeStruct {
	char* command;
	int index;
	struct CommandNodeStruct* next;
	};
typedef struct CommandNodeStruct CommandNode;

// Create command node
void CreateNode( CommandNode *thisNode, char* cmd, int ind, CommandNode *nextCmd) {

    PUSH_TRACE("CreateNode");
	thisNode->command = cmd;
	strcpy(thisNode->command,cmd);
	thisNode->index=ind;
	thisNode->next = nextCmd;
    POP_TRACE;
	return;
}

// Print input command
void PrintNodes( CommandNode *start){
	if(start == NULL){
	return;}

	fprintf(stdout,"%d: %s\n", start->index, start->command);
	PrintNodes(start->next);

}

// free current node
void FreeCurrNodes( CommandNode* node)
{
	CommandNode* nextNode= node->next;
	CommandNode* currNode=node;

	while(currNode != NULL)
	{
		free(currNode);

		if(nextNode !=NULL){
			CommandNode* tmpNode = nextNode;
			nextNode= nextNode->next;
			currNode = tmpNode;
		}else{
			currNode = NULL;
			}
	}
}

// allocate and store commands
char** allocate(char** arr, int rows, int cols)
{
	PUSH_TRACE("allocate");

	arr= (char**) malloc(sizeof(char*)*rows);
	for(int i=0; i<rows;i++){
		arr[i]=(char*)malloc(sizeof(char) *cols);
		}
	POP_TRACE();
	return arr;
	}

// function main
int main() {
    PUSH_TRACE("main");

    char input[100];

    // initialize the out file
    int out_file = open("memtrace.out", O_CREAT | O_APPEND | O_RDWR);
    chmod("memtrace.out", S_IRWXU);
    dup2(out_file, STDOUT_FILENO);

    // initialize char** commands
    int index = 0;
    char** commands = NULL;
    int rows = 5;
    int cols = 20;
    // call allocate function to store comands
    commands = allocate(commands, rows, cols);


    // initialize to create linklist
    CommandNode *headCommand = NULL;
    CommandNode *currNode = NULL;
    CommandNode *prevNode = (CommandNode*) malloc(sizeof(CommandNode));
    free(prevNode);

    // read commands from stdin
    while(fgets(input, sizeof(input), stdin)) {

        // remove the \n of input
        input[strcspn(input, "\n")] = '\0';

        // add columns if the size of command is larger
        if(strlen(input) > cols) {
            cols = strlen(input);
            commands = (char**) realloc(commands, sizeof(char*) * rows);
            for (int i = 0; i < rows; i++) {
                commands[i] = (char*) realloc(commands[i], sizeof(char) * (cols + 1));
            }
        }

        // add rows if more commands
        if(index == rows) {
            rows += 1;
            commands = (char**) realloc(commands, sizeof(char*) * rows);
            for (int i = 0; i < rows; i++) {
                commands[i] = (char*) realloc(commands[i], sizeof(char) * cols);
            }
        }

        // copy commands to the array
        strcpy(commands[index], input);

        // create linklist
        currNode = (CommandNode*) malloc(sizeof(CommandNode));
        CreateNode(currNode, commands[index], index, NULL);

        CommandNode* tmpNext = NULL;
        tmpNext = prevNode->next;
        prevNode->next= currNode;
        currNode->next=tmpNext;
        prevNode = currNode;
        if(index == 0) {
            headCommand = currNode;
        }

        PrintNodes(headCommand);
        index += 1;
    }

    // deallocate
    for(int i = 0; i < rows; i++) {
        free(commands[i]);
    }
    free(commands);
    // free(prevNode);
    FreeCurrNodes(headCommand);
    return 0;
}




