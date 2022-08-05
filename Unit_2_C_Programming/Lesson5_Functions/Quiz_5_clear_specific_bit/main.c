#include <stdio.h>
#include <stdlib.h>

int dec_to_bin(int num, int arr[]);
int bin_to_dec(int len, int arr[]);
int power(int num, int pow);
int main()
{
    int num, arr[100], bit, len;
    printf("Input number: ");
    scanf("%d", &num);
    //taking the bit position
    printf("Enter bit position: ");
    scanf("%d", &bit);
    //converting given number to binary
    len = dec_to_bin(num, arr);

    // clear the bit you entered
    if(bit > len)
        printf("Error! the original number  = %d", num);
    else
        arr[bit] = 0;

    printf("the decimal number after clear bit %d is %d\n", bit, bin_to_dec(len, arr));
    return 0;
}

int dec_to_bin(int num, int arr[])
{
    // This function convert the decimal to binary and return the length it
    int a ;
    for(a = 0; num>0; a++)
    {
        arr[a] = num % 2;
        num /= 2;
    }
    return a;
}
int bin_to_dec(int len, int arr[])
{
    // This function convert the binary to decimal and return the result decimal value
    int a, b, dec = 0;
    for(a = 0; a<len; a++)
    {
                dec = dec + arr[a]*power(2, a);
    }
    return dec;
}
int power(int num, int pow)
{
    // This function calc the power for the given number and power
    int a, result = num;
    if(pow == 0)
        return 1;
    else
    {
        for(a = 1; a<pow; a++)
        result *= num;
        return result;
    }

}
