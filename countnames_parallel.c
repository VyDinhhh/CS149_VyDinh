/**
 * Description: This program count the names in parallel from input files
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 3/06/2023
 * Creation date: 3/01/2023
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ROW 150
#define MAX_LEN 30

//struct to store names and numbers of names
struct my_data{
	char names[MAX_LEN];
	int count;
	
};
struct my_data namecounts[MAX_ROW]={0};
struct my_data total_names[MAX_ROW]={0};

/*
* count name in a file and write to a pipe
* parameters: FILE*, int, char*
* return: nothing
*/
void countNames(FILE* file, int writeId, char* fileNumber){

    
     char name[MAX_ROW][MAX_LEN];
  
     int index=0;
     int count=0;
     
     while(fgets(name[index],MAX_LEN, file)){
     
     //replace the end of line with \0
     name[index][strlen(name[index])-1]='\0';
     
     if(strlen(name[index])==0)
     {
     	fprintf(stderr,"%s%d%s%s\n","Warning - Line ", count+1, " is empty from file ", fileNumber);
     }else
     {
     	//Remove leading space
     	int i=0;
     	while(name[index][i]==' '){
     	     i++;
     }
     if(i>0){
     	memmove(name[index], name[index]+i,strlen(name[index])-i+1);
     	}
     	index++;
     }
     	count++;
     }
     
     int temp_index=0;
     int count_distinct=0;
     for(int i=0;i<count;i++){
     	if(name[i][0] == '\0'){
     	
     		break;
     	}
     	int is_distinct=1;
     	//compare to find the distinct names
     	for(int j =0;j<temp_index;j++){
     	    if(strcmp(name[i],namecounts[j].names)==0){
     	    namecounts[j].count++;
     	    is_distinct=0;
     	    break;
     	  }
     	 }
     	 
     	 //add name to struct
     	 if(is_distinct){
     	 strcpy(namecounts[temp_index].names,name[i]);
     	 namecounts[temp_index].count=1;
     	 temp_index++;
     	 }
     }	
     
     
     fclose(file);
     
     //write to pipe
     write(writeId, &temp_index, sizeof(temp_index));
     write(writeId, namecounts, sizeof(struct my_data)*temp_index);
     
     exit(0);
}


int main(int argc, char *argv[]){
    int fd[2];
    int status;
    //check if the file is at least 1
    if(argc<2){
    printf("Range:cannot open file %s\n", argv[0]);
    exit(0);
    }
    //check success of pipe
    if(pipe(fd)==-1){
    	fprintf(stderr, "Pipe failed");
    	return 1;
    }
    
    //loop to fork() to read mul files
    for(int i=1; i<argc;i++){
    int pid=fork();
    if(pid == 0){
    	//read file argv[i]
    	close(fd[0]);
    	
    	char *fileName=argv[i];
    	
    	FILE *fp= fopen(fileName,"r");
    	//check if file id NULL
    	if(fp==NULL)
    	{  
     
     	printf("Error: cannot open file\n");
     	exit(0);
         }
        // call function counNames	
    	countNames(fp,fd[1],fileName);
    	
    	close(fd[1]);
    	exit(0); //to stop child contnuing fork its own child
    	}else{
    	wait(NULL);
    	
    	// test if the processes terminate normally
    	//pid_t cpid;
    	//while((cpid=wait(&status))>0){
    	//	if(WIFEXITED(status)){
    	//	fprintf(stderr,"Child %d terminated normally %d\n", pid, WEXITSTATUS(status));
    	//	}else if (WIFSIGNALED(status)){
    	//	fprintf(stderr,"Child %d terminated abnormally %d\n", pid, WTERMSIG(status));}
    	//	}
    		
    		
    	
    	}
    }
    
    //parent
       
    
    close(fd[1]);
    int temp_index=0;
    int total_index=0;
    // loop to arregate 
    for(int i = 1; i < argc; i++) {
    
    	// read to pipe in parent process
        read(fd[0], &temp_index, sizeof(temp_index));
        total_index += temp_index;
        read(fd[0], &namecounts, sizeof(struct my_data) * temp_index);
        // loop to count name from all files
        for(int j = 0; j < temp_index; j++) {
            bool name_found = false;
            // if name exits, add counts
            for(int k = 0; k < total_index; k++) {
                if(strcmp(namecounts[j].names, total_names[k].names) == 0) {
                    total_names[k].count += namecounts[j].count;
                    name_found = true;
                    break;
                }
            }
            //if name not found add the new name
            if(!name_found) {
                strcpy(total_names[total_index - temp_index + j].names, namecounts[j].names);
                total_names[total_index - temp_index + j].count = namecounts[j].count;
            }
        }
    }

    close(fd[0]);

    //print out all names and counts
    for(int i = 0; i < total_index; i++) {
    	if(strlen(total_names[i].names)>1){
        printf("%s: %d\n", total_names[i].names, total_names[i].count);
        }
    }
    

    return 0;
}
    
    

