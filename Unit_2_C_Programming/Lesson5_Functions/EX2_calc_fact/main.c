#include <stdio.h>
#include <stdlib.h>

unsigned calc_fact(unsigned num);

int main()
{
    unsigned n, fact;
    printf("Enter an positive integer: ");
    scanf("%d", &n);
    fact = calc_fact(n);
    printf("Factorial of %d = %d", n, fact);
    return 0;
}


unsigned calc_fact(unsigned num)
{
    // This function calculate the factorial for the entered number
    if(num == 0)
        return 1;
    else
        return num * calc_fact(num - 1);
}
