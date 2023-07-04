#include <stdio.h>
#include <stdlib.h>

int last_occurrence(int arr[], int size, int elem);
int main()
{
    int arr[100], i, size, elem, occur;
   printf("Enter the number of elements: ");
   scanf("%d", &size);
   for(i = 0; i< size; i++)
   {
        printf("Enter the element with index %d: ", i);
        scanf("%d", &arr[i]);
   }

    printf("Enter the element you want to found: ");
    scanf("%d", &elem);
    printf("The LAST occurrence of %d at index %d", elem, last_occurrence(arr, size, elem));
    return 0;
}

int last_occurrence(int arr[], int size, int elem)
{
       int  i, occur;


       for(i = size -1; i>0; i--)
       {
            if(elem == arr[i])
            {
                occur = i;
                break;
            }
       }
       return occur;

}
