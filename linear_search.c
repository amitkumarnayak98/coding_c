#include <stdio.h>
#include "myfunctions.h"
#include <time.h>

int main()
{
    int n, target, index;

    // Get the user input for the range of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // If we type a negative number for the range then show this message
    if (n <= 0)
    {
        printf("Invalid size, Please enter a positive size.\n");
        return 1;
    }

    int arr[n];
    int i;

    // Get the user input for the each element of the array
    printf("Enter the element of the array:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the entered array
    printf("Entered array[]: ", arr);
    printArray(i, arr, n);

    // Taking the element to be searched
    printf("\nEnter the element to search: ");
    scanf("%d", &target);

    // Performing the linear search
    index = linearSearch(arr, n, target, i);

    // Printing the result
    if (index != -1)
    {
        printf("Element %d found at index %d.\n", target, index);
    }
    else
    {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
