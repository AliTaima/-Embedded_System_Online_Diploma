#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[100];
    fgets(str, 100, stdin);  // fgets function take \n with the name so it add 1 to the original size
     int size = strlen(str);
     //printf("the size = %d", size - 1);
    rev_word_str(str, size-1);


    return 0;
}

void rev_word_str(char str[], int size)
{
    /*
    In this function I start from the last elem. in the array and start to store it in ch array with reverse order until i find the space
    so when i found the space I begin to print the string in ch array with reverse order(reverse of reverse will become the original)
    and the word printed correctly and so on
    */
    int i, j, k = 0;
    char ch[50];
    for(i = size-1; i>=0; i--)
    {
        if(str[i] == ' ')
        {
            for(j = k-1; j>=0; j--)
            {
                printf("%c", ch[j]);
            }
            printf(" ");
            k = 0;
        }
        else
        {
            ch[k] = str[i];
            k++;
        }
    }
    if(k != 0)
    {
        for(j = k-1; j>= 0; j--)
        printf("%c", ch[j]);
    }

}
