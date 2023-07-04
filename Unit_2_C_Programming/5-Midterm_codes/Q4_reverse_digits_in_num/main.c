#include <stdio.h>
#include <stdlib.h>

void reverse_num(int num);
int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    reverse_num(num);
    return 0;
}

void reverse_num(int num)
{
    while(num)
    {
        printf("%d", num%10);
        num /= 10;
    }

}
