/**
 * Description: This program parse string with comma
 * Author names: Vy Dinh
 * Author emails: thithuyvy.dinh@sjsu.edu
 * Last modified date: 4/3/2023
 * Creation date: 4/3/2023
 **/
#include<stdio.h>
#include <string.h>

int main(void) {

    char input[100];
    char *first_word;
    char *second_word;

    while (1) {
        printf("Enter input string:\n");
        fgets(input, sizeof(input), stdin);
        input[strlen(input)-1] = 0; // remove newline

        //stop if input is q
        if (strcmp(input, "q") == 0) {
            break;
        }

        // find the position of comma
        char *comma_pos = strchr(input, ',');
        if (comma_pos == NULL) {
            printf("Error: No comma in string.\n\n");
            continue;
        }

        *comma_pos = '\0'; // replace comma with null terminator

        // use strtok to split string and space
        first_word = strtok(input, " ");
        second_word = strtok(comma_pos + 1, " ");

        printf("First word: %s\n", first_word);
        printf("Second word: %s\n", second_word);
        printf("\n");
    }

    return 0;


}
