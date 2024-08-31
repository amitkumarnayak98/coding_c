#include <stdio.h>
#include "myfunctions.h"

int getIndexOfElement(int arr[], int n, int target)
{
    int a;
    for (a = 0; a < n; a++)
    {
        if (arr[a] == target)
        {
            return a;
        }
    }
    return -1;
}

int main()
{
    int n, target, index, result, e;

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

    // Get the user input for each element of the array
    printf("Enter the element of the array:\n");

    for (index = 0; index < n; index++)
    {
        printf("Enter element %d: ", index + 1);
        scanf("%d", &arr[index]);
    }

    // Print the entered array
    printf("Entered array[]: ", arr);
    printArray(index, arr, n);

    // Sorting the array in ascending using the bubble sort
    bubbleSort(arr, n);

    // Printing the sorted array
    printf("\nSorted array[] in ascending order: ");
    printArray(index, arr, n);

    // Taking the element to be searched
    printf("\nEnter the element to search: ");
    scanf("%d", &target);

    // Performing the binary search
    result = binarySearch(arr, n, target);

    e = getIndexOfElement(arr, n, target);

    // Printing the result
    if (result != -1)
    {
        printf("\nElement %d is present at index %d.\n", target, e);
    }
    else
    {
        printf("Element %d is not present in the array.\n", target);
    }

    return 0;
}