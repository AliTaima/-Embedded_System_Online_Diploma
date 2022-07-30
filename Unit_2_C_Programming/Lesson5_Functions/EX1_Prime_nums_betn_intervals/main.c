#include <stdio.h>
#include <stdlib.h>
int PBI(int num1, int num2, int prime[]);
int main()
{
    int n1, n2, prime_num[100];
    printf("Enter two numbers(intervals): ");
    scanf("%d %d",&n1, &n2);
    int count = PBI(n1, n2, prime_num);
    // print prime numbers
    printf("Prime numbers between %d and %d are:  ", n1, n2);
    for(int a = 0; a < count; a++)
    {
        printf("%d ", prime_num[a]);
    }

    return 0;
}

int PBI(int num1, int num2, int prime[])
{
    //this function finds the prime numbers between two intervals and return the number of them

    int i, j, flag, count = 0;
    for(i = num1; i<= num2; i++)
    {
        flag = 0;
        for(j = 2; j<i/2; j++)
        {
            if(i%j == 0)
            {
                flag = 1;
                break;
            }

        }
        if(flag == 0)
        {
            prime[count] = i;
            count ++;
        }

    }
    return count;

}


