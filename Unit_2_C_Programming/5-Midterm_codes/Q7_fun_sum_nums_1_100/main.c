#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, result ;
    printf("Enter a number less than 100: \n");
    scanf("%d", &num);
    result = sum(num);
    printf("The summation of the numbers from %d to 100 = %d", num, result);
    return 0;
}

int sum(int num)
{
    //This function return the summation of numbers from the given number(less than 100) to 100

    // base condition to return 100
    if(num == 100)
        return num;
    // recursion until the base condition is become true
    else
        return num + sum(num+1);
}
