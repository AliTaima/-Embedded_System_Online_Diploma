#include <stdio.h>
#include <stdlib.h>
int calc_power(int num, unsigned power);
int main()
{
    int n, result;
    unsigned power;
    printf("Enter base number: ");
    scanf("%d", &n);
    printf("Enter power number(positive integer): ");
    scanf("%d", &power);
    result = calc_power(n, power);
    printf("%d ^ %d = %d", n, power, result);
    return 0;
}

int calc_power(int num, unsigned power)
{
    // This function calculate the power of the given number

    //base case to return the base number if the power is 1
    if(power == 1)
        return num;
    // continue and subtract 1 from power until satisfy the base condition
    else
        return num*calc_power(num, power - 1);
}
