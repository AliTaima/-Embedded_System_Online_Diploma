#include <stdio.h>
#include <stdlib.h>


int main()
{
   fun();


    return 0;
}
void fun()
{
     char a = 0, arr[100], i;
    scanf("%c", &arr[a]);
    while(arr[a] != '\n')
    {
         a++;
         scanf("%c", &arr[a]);
    }
    for(i = a - 1;i>=0;i--)
    {
        printf("%c", arr[i]);
    }
}
