#include <stdio.h>
#include <stdlib.h>
void reverse_arr(int arr[], int size);
void scan_arr(int arr[], int size);
void print_arr(int arr[], int size);

int main()
{
    int arr[100], size;
    printf("Please enter the size of your array: \n");
    scanf("%d", &size);
    scan_arr(arr, size);

     reverse_arr(arr, size);
    printf("The array after reversing its elements: \n");
    print_arr(arr, size);
    return 0;
}

void reverse_arr(int arr[], int size)
{
    int a, b, temp[100];
    for(a = size-1, b = 0; a>=0; a--, b++)
    {
        temp[b] = arr[a];
    }
    for(a = 0; a<size; a++)
    {
        arr[a] = temp[a];
    }

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
void print_arr(int arr[], int size)
{
    // This function printing the array elements
    int a;
    for(a = 0; a<size; a++)
    {
        printf("index%d = %d\n", a, arr[a]);
    }
}
