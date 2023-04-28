/*
 * main.c
 *
 *  Created on: Jan 28, 2023
 *      Author: Ali Mohamed Taima
 */
#include <stdio.h>
#include <string.h>
int main()
{
	char line[1000];
	char temp[1000];
    int is_count = 0;
    int are_count = 0;
    printf("Enter a sentence: ");
    fgets(line, sizeof(line), stdin);
    // Get the first word in the sentence
    char *token = strtok(line, " \n");
    // Iterate until find the null
    while (token != NULL)
    {
        // check if the word is "it", "he", "she" (I compare with stricmp to get upper and lower cases of letters)
        if(!stricmp(token, "it") || !stricmp(token, "he") || !stricmp(token, "she"))
        {
            // store the word in temp string
            strcat(temp, token);
            // add white space to organize string
            strcat(temp, " ");

            // Get the next string to compare
            token = strtok(NULL, " \n");
            // check if we reach the end or not(as I may find these words at the end of string)
            if(token == NULL)
                break;
            else
            {
                // If next word is "is" so the sentence is correct, else there is a grammatically error
                if(!stricmp(token, "is"))
                    continue;
                else
                {
                    // count gramtically error and correct it
                    is_count++;
                    strcat(temp, "is ");
                }
            }
        }
        else if(!stricmp(token, "we"))
        {
            // I make the same steps as previous with "are", and "we"
            strcat(temp, token);
            strcat(temp, " ");
            token = strtok(NULL, " \n");
            // check if we reach the end or not
            if(token == NULL)
                break;
            else
            {
                if(!stricmp(token, "are"))
                    continue;
                else
                {
                    are_count++;
                    strcat(temp, "are ");
                }
            }
        }
        else
        {
            // I store the word as it
            strcat(temp, token);
            strcat(temp, " ");
        }
        // Getting the next word to compare in while loop
        token = strtok(NULL, " \n");
    }
    strcat(temp, "\0");
    /*
        I have two options
        1- if my counts still 0, so the sentence is correct and I should print
        that is correct

        2- if there is any errors I already correct them when I store in temp string
        so I should count these errors and print the correct sentence that stored in
        temp string

    */
    if(is_count > 0 || are_count > 0)
    {
        printf("Grammatical Errors: %d\n", is_count + are_count);
        printf("Corrected Sentence: %s", temp);
    }
    else
        printf("The sentence is grammatically correct!");
	return 0;
}

