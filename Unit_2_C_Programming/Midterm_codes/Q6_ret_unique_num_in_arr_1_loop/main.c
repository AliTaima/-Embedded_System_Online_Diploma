#include <stdio.h>
#include <stdlib.h>
int unique_num(int arr[], int size, int index);
void scan_arr(int arr[], int size);
int flag; // global variable used to check that the array end and not found unique number or not
int main()
{
    int arr[100], size;
    printf("Please enter the size of your array: \n");
    scanf("%d", &size);
    scan_arr(arr, size);
    printf("the unique number = %d", unique_num(arr, size, 0));
    return 0;
}

int unique_num(int arr[], int size, int index)
{
    // This function finds the unique number in the given array by recursion and one for loop
    int a;
    for(a = 0; a<size; a++)
    {
        // Escape comparing the same element
        if(a == index)
            continue;
        // checking if the current element equal to any element in the array or not
        if(arr[a] == arr[index])
            {
                flag = 1;
                break;
            }
    }
    // checking the end or the array and decide that the array has unique number or not
    if((index == (size -1)) && (flag == 1) && (a!=size))
    {
        printf("There is no unique number in the array");
        exit(1);
    }

    if(a == size || index == (size -1) )
        return arr[index];
    else
        unique_num(arr, size, index +1);
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
