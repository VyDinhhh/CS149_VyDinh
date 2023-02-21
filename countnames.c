/**
 * Description: This program count the names, which read from a file
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 2/19/2023
 * Creation date: 2/15/2023
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    const int MAX_ROW=150;
    const int MAX_LENGTH=30;

    //check if the filename passed as argument is valid
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(0);
    }
    
    char *fileName=argv[1];
    FILE *fp = fopen(fileName, "r");
    
    char name[MAX_ROW][MAX_LENGTH];
    //check if file is able to open
    if(fp==NULL)
    {
        printf("error: cannot open file\n");
        exit(1);
    }

    int index =0;
    int count=0;
    

    while (fgets(name[index], MAX_LENGTH, fp)) { 

	//replace the end of line with \0
        name[index][strlen(name[index])-1]='\0'; 
        
        //stderr if the line is empty - check if the length of string is 0
        if(strlen(name[index])==0)
        {
          
            fprintf(stderr,"%s%d%s\n", "Warning - Line ",  count+1 , " is empty.");
            
        }else
        {
        // Remove leading spaces if the name acciidentally start with space
        int i = 0;
        while (name[index][i] == ' ') {
            i++;
        }
        if (i > 0) {
            memmove(name[index], name[index]+i, strlen(name[index])-i+1);
        }
        index++;
    }
          
        count++;
        
    }
    
    // create a new array to store a unique name
    char temp[MAX_ROW][MAX_LENGTH];
    //the loop to check if the name is distinct 
    int temp_index=0;
    for (int i = 0; i < count; i++) {
        if (name[i][0] == '\0') {
            break;
        }
        int is_distinct = 1;
        //if the name exists, it is not distinct so not add it to array
        for (int j = 0; j < temp_index; j++) {
            if (strcmp(name[i], temp[j]) == 0) {
                is_distinct = 0;
                break;
            }
        }
        // add the name if distinct is true
        if (is_distinct) {
            strcpy(temp[temp_index], name[i]);
            temp_index++;
        }
    }
   
  
    int number_individual_name=0;
    //counting the numbers of a name
    for(int i =0; i<temp_index;i++)
    {
        for(int j=0; j<index;j++)
        {
            //if there is same name, increase the number of name
            if((strcmp(temp[i],name[j]))==0)
            {
                number_individual_name++;
                
            }
            
        }
        
        //this is to check the last line empty in a file to ignore
        if(number_individual_name!=0){
        fprintf(stdout,"%s: %d\n",temp[i],number_individual_name);
        }
        
        
        number_individual_name=0;
    }   
    //close file   
    fclose(fp);
    return 0;
}
