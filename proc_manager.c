/**
 * Description: This program execute the commands from stdin
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 4/26/2023
 * Creation date: 4/20/2023
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <wait.h>
#include <time.h>
#include <sys/stat.h>
#include "CommandNodeLL.h"


int main()
{


    // initialize vars for reading from stdin
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char newString[20][20];
    int i, j, commandLine;


    // initialize and create linklist
    CommandNode *headPtr = NULL;
    CommandNode *currNode = NULL;
    CommandNode *prevNode = (CommandNode *)malloc(sizeof(CommandNode));
    
    int node_count = 0;

    // Read each line of the file
    while ((read = getline(&line, &len, stdin)) != -1)
    {


        // remove /n
        line[strlen(line) - 1] = 0;

        j = 0;
        commandLine = 0;
        for (i = 0; i <= (strlen(line)); i++)
        {

            // If space or NULL found, assign NULL into newString[ctr]
            if (line[i] == ' ' || line[i] == '\0')
            {
                newString[commandLine][j] = '\0';
                commandLine++;
                j = 0;
            }
            else
            {
                newString[commandLine][j] = line[i];
                j++;
            }
        }


        // create node and insert to linklist
        currNode = (CommandNode *)malloc(sizeof(CommandNode));
        CreateCommandNode(currNode, newString, node_count, commandLine, NULL);
        InsertCommandAfter(prevNode, currNode);
        prevNode = currNode;
        node_count += 1;


        // track the node
        if ((node_count) == 1)
        {
            headPtr = currNode;
        }
    }


    // declare vars of timer
    struct timespec start, finish;
    double elapsed;


    // head pointer of the list to start
    currNode = headPtr;
    int child_pid;
    while (currNode != NULL)
    {
        child_pid = fork();

	clock_gettime(CLOCK_MONOTONIC, &start);
        // check fork status
        if (child_pid < 0)
        {
            fprintf(stderr, "Fork failed\n");
            exit(2);
        }
        // child process
        if (child_pid == 0)
        {
            // redirect to .out and .err files
            char out_file_name[10];
            char err_file_name[10];
            sprintf(out_file_name, "%d.out", getpid());
            sprintf(err_file_name, "%d.err", getpid());
            int out_file = open(out_file_name, O_RDWR | O_CREAT | O_APPEND, 0777);
            int err_file = open(err_file_name, O_RDWR | O_CREAT | O_APPEND, 0777);
            dup2(out_file, STDOUT_FILENO);
            dup2(err_file, STDERR_FILENO);


            // begin the timer ans store it
            
            currNode->starttime = start.tv_nsec;


            char *cmds[20];
            int cmd_ind = 0;


            // store commands
            while (commandLine < 20)
            {
                char currChar = *(currNode->command[cmd_ind]);
                if (currChar == '\0')
                {
                    break;
                }
                cmds[cmd_ind] = currNode->command[cmd_ind];
                cmd_ind += 1;
            }

            cmds[cmd_ind] = NULL;


            fprintf(stdout, "Starting command %d: child %d pid of parent %d\n", currNode->index, getpid(), getppid());
            fflush(stdout);


            // Execute the command
            execvp(cmds[0], cmds);

            // if exc failed
            perror(cmds[0]);
            exit(2);
        }

        // Parent process
        else
        {
            currNode->PID = child_pid;
        }

        currNode = GetNextCommand(currNode);
       
    }


    // wait
    int status;
    while ((child_pid = wait(&status)) >= 0)
    {


        CommandNode *child_ptr = FindCommand(headPtr, child_pid);
        // get the file name
        int filen = child_ptr->PID;


        // Calculate time when finish
        clock_gettime(CLOCK_MONOTONIC, &finish);
        elapsed = (finish.tv_sec - (child_ptr->starttime));
        //elapsed+=(finish.tv_nsec - (child_ptr->starttime))/1000000000.0;


    // redirect to .out and .err files
        char out_file_name[10];
        char err_file_name[10];
        sprintf(out_file_name, "%d.out", filen);
        sprintf(err_file_name, "%d.err", filen);
        int out_file = open(out_file_name, O_RDWR | O_CREAT | O_APPEND, 0777);
        int err_file = open(err_file_name, O_RDWR | O_CREAT | O_APPEND, 0777);
        dup2(out_file, STDOUT_FILENO);
        dup2(err_file, STDERR_FILENO);


        // get status of child pid
        if (WIFEXITED(status))
        {
            fprintf(stderr, "Exit with exitcode = %d\n", WEXITSTATUS(status));
            
        // message to .err file if it is too fast
       
        }
        else if (WIFSIGNALED(status))
        {
            fprintf(stderr, "Killed with signal %d\n", WTERMSIG(status));
        }


        // runtime output
        fprintf(stdout, "Finished at %ld, runtime duration %f\n", finish.tv_sec, elapsed);
        fflush(stdout);
        // child pid output
        fprintf(stdout, "Finished child PID %d pid of parent %d\n", child_pid, getpid());
        fflush(stdout);


       if(elapsed <=2){
       fprintf(stderr, "Spawning too fast\n");
       }else{
            // program restart if elapsed > 2
     
            child_pid = fork();

	char out_file_name[10];
            char err_file_name[10];
            sprintf(out_file_name, "%d.out", getpid());
            sprintf(err_file_name, "%d.err", getpid());
            int out_file = open(out_file_name, O_RDWR | O_CREAT | O_APPEND, 0777);
            int err_file = open(err_file_name, O_RDWR | O_CREAT | O_APPEND, 0777);
            dup2(out_file, STDOUT_FILENO);
            dup2(err_file, STDERR_FILENO);
            fprintf(stdout,"RESTARTING");
            
            // fork failed message
            if (child_pid < 0)
            {
                fprintf(stderr, "fork failed\n");
                exit(2);
            }

            clock_gettime(CLOCK_MONOTONIC, &start);
            child_ptr->starttime = start.tv_sec;


            // child process
            if (child_pid == 0)
            {


                char *cmds[20];
                int cmd_ind = 0;



                while (commandLine < 20)
                {
                    char currChar = *(currNode->command[cmd_ind]);
                    if (currChar == '\0')
                    {
                        break;
                    }
                    cmds[cmd_ind] = currNode->command[cmd_ind];
                    cmd_ind += 1;
                }

                cmds[cmd_ind] = NULL;

		
                fprintf(stdout, "Starting command %d: child %d pid of parent %d\n", currNode->index, getpid(), getppid());
                fflush(stdout);


                // execute the command
                execvp(cmds[0], cmds);
                perror(cmds[0]);
                exit(2);
            }
            else
            {
                child_ptr->PID = child_pid;
            }
            
            
        }
       
    }


    return 0;
}






