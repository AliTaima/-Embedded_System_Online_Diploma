#include <stdio.h>
#include <stdlib.h>
int check_bin_ones(int num);
int main()
{
     int num, result ;
    printf("Enter a number: ");
     scanf("%d", &num);
    result = check_bin_ones(num);
    printf("The number of ones in the binary of the number = %d", result);
    return 0;
}

int check_bin_ones(int num)
{
    /* This function calculate the number of ones in the binary representation the
    entered number
    */
    int a, digit, count = 0;
    for(a = 0; a<32; a++)
    {
        // shift left to check each digit in the integer is one or not
        digit = 1<<a;
        // making bitwise and with each digit
        if(num & digit)
            count ++;
    }

    return count;
}
