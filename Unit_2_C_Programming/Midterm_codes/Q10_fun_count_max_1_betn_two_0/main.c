#include <stdio.h>
#include <stdlib.h>
int count_1(int num, int arr[]);
int main()
{
    int num, arr[100], result;
    printf("Input number: ");
    scanf("%d", &num);
    result = count_1(num, arr);
    printf("The maximum number of 1's = %d", result);
    return 0;
}

int count_1(int num, int arr[])
{
    // This function return the max number of zeros between two 0's in the binary representation of the number
    int rem, flag = 0, max = 0, count = 0;
    while(num)
    {
        rem = num%2;
        num /= 2;
        if(rem == 0)
        {
            if(max < count)
            {
                max = count;
                flag = 1;
                /*
                 I use this flag to make sure that the assigning occur betn max and count
                 as in some cases we can't get the last zero in the number
                */
            }

            count = 0;
            continue;
        }
        if(rem == 1)
                count ++;

    }
    if(flag == 1)
        return max;
    else
        return count;
}
