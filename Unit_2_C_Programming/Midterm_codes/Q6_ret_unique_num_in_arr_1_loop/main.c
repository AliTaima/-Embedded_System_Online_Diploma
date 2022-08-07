#include <stdio.h>
#include <stdlib.h>
int unique_num(int arr[], int size);
void scan_arr(int arr[], int size);
int flag; // global variable used to check that the array end and not found unique number or not
int main()
{
    int arr[100], size;
    printf("Please enter the size of your array: \n");
    scanf("%d", &size);
    scan_arr(arr, size);
    printf("the unique number = %d", unique_num(arr, size));
    return 0;
}

int unique_num(int arr[], int size)
{
    /*
        The idea here understanding the xor operator that return 0 if the two numbers are equal and return the number
        that xoring with 0
    */
    int res = 0, i;
    for(i = 0; i<size; i ++)
        res ^= arr[i];
    return res;
}

void scan_arr(int arr[], int size)
{
    // This function scan the array elements from the user
    int a;
    printf("Enter the elements of the array: \n");
    for(a = 0; a<size; a++)
    {
        scanf("%d", &arr[a]);
    }
}
