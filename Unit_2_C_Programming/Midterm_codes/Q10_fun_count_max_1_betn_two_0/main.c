#include <stdio.h>
#include <stdlib.h>
int count_1(int num);
int main()
{
    int num, result;
    printf("Input number: ");
    scanf("%d", &num);
    result = count_1(num);
    printf("The maximum number of 1's = %d", result);
    return 0;
}

int count_1(int num)
{

    int count = 0;
    while(num != 0)
    {
        num = (num &(num << 1));
        count ++;
    }
    return count;
}
