#include <stdio.h>
#include <stdlib.h>

void reverse_str();
int main()
{

    printf("Enter sentence: ");
    reverse_str();

    return 0;
}

void reverse_str()
{
    // This functions reverse the entered sentence using recursion
    char c;
    scanf("%c", &c);
    if( c != '\n')
    {
        reverse_str();
        printf("%c", c);

    }

}
