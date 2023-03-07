/**
 * Description: This program print the reverse 
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 3/5/2023
 * Creation date: 3/4/2023
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	// create new process
    int pid1=fork();
    int pid2=fork();
    
    // use condition to print PID correctly
    if(pid1>0&&pid2>0)
    { 
    printf("Hello from process with PID %d\n", (int) getpid());
            
    }else if(pid1>0&&pid2==0){
    printf("Hello from process with PID %d\n", (int) getpid());
     exit(0);       
    }else if(pid1==0&&pid2>0){
    printf("Hello from process with PID %d\n", (int) getpid());
      exit(1);     
    }else{
    printf("Hello from process with PID %d\n", (int) getpid());
      exit(2);      
    }
    
    
    return 0;
}

