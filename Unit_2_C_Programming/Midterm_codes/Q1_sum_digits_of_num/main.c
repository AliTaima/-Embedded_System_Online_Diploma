#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, s;
    printf("Enter a number: ");
    scanf("%d", &num);
    s = sum_digits(num);
    printf("Them summation of digits = %d", s);

    return 0;
}
int sum_digits(int num)
{
    int sum = 0, rem;
    while(num)
    {
        rem = num %10;
        sum += rem;
        num /= 10;
    }
    return sum;
}
