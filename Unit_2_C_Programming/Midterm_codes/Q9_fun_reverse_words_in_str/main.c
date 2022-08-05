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

void rev_word_str(char str[100], int size)
{
    int a, b, t = 0, a_temp;
    char temp[100];
    // reversing the given string
    for(a = size-1, b = 0; a>=0; a--, b++)
    {
        temp[b] = str[a];
    }
    temp[b] = '\0';  //add the null at the end of the string

   for(a = 0; a<=size; a++)
   {

       if(temp[a] == ' ' || temp[a] == '\0')
       {
            /* When we find white space or null we return back in the string and store it in reverse order
            for example amiaT ilA --> amiaT (find white space) so store --> Taima then continue and so on
            */
           for(b = t, a_temp = a - 1; b < a; b++, a_temp-- )
           {
                str[b] = temp[a_temp];
           }
           if(temp [a] != '\0')
           {
               str[b] = ' ';
               t = t+a+1;
           }


       }
    }
    str[b] = '\0'; //add the null at the end of the string
   printf("%s", str);

}
