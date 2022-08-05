#include <stdio.h>
#include <stdlib.h>

int dec_to_bin(int num, int arr[]);
int main()
{
    int num, arr[100];
    printf("Input number: ");
    scanf("%d", &num);
    printf("The 4th bin in binary number of %d is %d", num, dec_to_bin(num, arr));

    return 0;
}

int dec_to_bin(int num, int arr[])
{
    // This function convert the decimal to binary and the forth bit in the result binary number
    int a ;
    for(a = 0; num>0; a++)
    {
        arr[a] = num % 2;
        num /= 2;
    }
    return arr[3];

}
