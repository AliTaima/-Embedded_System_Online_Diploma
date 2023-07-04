#include <stdio.h>
#include <stdlib.h>
int calc_prime(int num1, int num2, int prime[]);
void print_arr(int arr[], int size);
int main()
{
    int num1, num2, prime[100], size;
    printf("Enter two number:\n");
    scanf("%d %d", &num1, &num2);
    size = calc_prime(num1, num2, prime);
    printf("The prime numbers are:\n");
    print_arr(prime, size);

    return 0;
}

int calc_prime(int num1, int num2, int prime[])
{
    /*This function used to calculate the prime numbers between the given two numbers
    and returning the number of prime numbers that stored in the prime array
    */
    int a, b, count = 0, flag;
    /*
        a, b used as loop counter
        count uses to store number in array
        flag uses to show the condition of prime satisfied or not
    */
    for(a = num1; a<=num2; a++)
    {
        flag = 0;
        // check the division of the number with number less than it to check it prime or not
        for(b = 2; b<a; b++)
        {
            if(a % b == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            prime[count] = a;
            count++;
        }
    }
    return count;
}
void print_arr(int arr[], int size)
{
    int a;
    for(a = 0; a<size; a++)
        printf("%d\n", arr[a]);
}
