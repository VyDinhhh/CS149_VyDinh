/**
 * Description: This program reads commands from stdin and redirect output to files
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 3/22/2023
 * Creation date: 3/19/2023
 **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>


#define MAX_COMMANDS 100
#define MAX_LENGTH 30


int main()
{
    char commands[MAX_COMMANDS][MAX_LENGTH];
    int i = 0;


    // read commands from stdin
    while (fgets(commands[i], MAX_LENGTH, stdin))
    {
        // remove newline
        commands[i][strlen(commands[i]) - 1] = '\0';


        if (strcmp(commands[i], "") == 0)
        {
            // skip empty command
            continue;
        }
        // count the commands
        i++;
    }


    int num_commands = i;
    int child_pid, status;
    // store the child pid to an array
    int file_pid[num_commands];
    for (i = 0; i < num_commands; i++)
    {
        child_pid = fork();
        // chile process
        if (child_pid == 0)
        {

            char out_filename[10];
            char err_filename[10];
            sprintf(out_filename, "%d.out", getpid());
            sprintf(err_filename, "%d.err", getpid());
            // open file
            int out_fd = open(out_filename, O_RDWR | O_CREAT | O_APPEND, 0777);
            int err_fd = open(err_filename, O_RDWR | O_CREAT | O_APPEND, 0777);


            if (out_fd < 0 || err_fd < 0)
            {
                perror("Error opening file");
                exit(2);
            }


            // redirect stdout and stderr to files
            dup2(out_fd, STDOUT_FILENO);
            dup2(err_fd, STDERR_FILENO);


            char *buff[4];
            buff[0] = "/bin/sh";
            buff[1] = "-c";
            buff[2] = commands[i];
            buff[3] = NULL;


            // print the statement to stdout file
            fprintf(stdout, "Starting command %d: child PID %d pid of parent %d\n", i + 1, getpid(), getppid());
            fflush(stdout);

            // exec by input commands
            execvp(buff[0], buff);
            perror("Execvp failed");
            exit(2);
        }
        else if (child_pid < 0)
        {
            perror("fork failed");
            exit(2);
        }else{
            file_pid[i]=child_pid;
            //printf("%d %d\n", file_pid[i], child_pid);
        }

    }


    int file_count = 0;
    // wait for child processes to finish
    while (wait(&status) > 0)
    {
        char out_filename[10];
        char err_filename[10];
        // using file name from pid
        int fileName = file_pid[file_count];
        sprintf(out_filename, "%d.out", fileName);
        sprintf(err_filename, "%d.err", fileName);


        int out_fd = open(out_filename, O_RDWR | O_CREAT | O_APPEND, 0777);
        int err_fd = open(err_filename, O_RDWR | O_CREAT | O_APPEND, 0777);


        if (out_fd < 0 || err_fd < 0)
        {
            perror("Error opening file");
            exit(2);
        }


        // redirect to files
        dup2(out_fd, STDOUT_FILENO);
        dup2(err_fd, STDERR_FILENO);


        // normal termination with an exitcode
        if (WIFEXITED(status))
        {


            fprintf(stderr, "Exited with exitcode = %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))// abnormal termination with a signal
        {


            fprintf(stderr, "Killed with signal %d\n", WTERMSIG(status));
        }
        //print to .out file
        fprintf(stdout, "Finished child PID %d pid of parent %d\n", child_pid, getpid());
        fflush(stdout);


        // index to keep track of .out and .err file
        file_count++;
    }


    return 0;
}




