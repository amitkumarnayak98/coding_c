#include <stdio.h>
#include <time.h>
#include "myfunctions.h"

int main()
{
    int i, n, arr1[n];

    // For Array1

    // Get the user input for the particular range for the array1
    printf("Enter the size of the array1: ");
    scanf("%d", &n);

    // If we type a negative range then show the error message
    if (n <= 0)
    {
        printf("Invalid size, Please enter a positive size for range.\n");
        return 1;
    }

    // Get the user input for the each element of the array
    printf("Enter the element of the array1:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    // Print the entered array
    printf("Entered array1[]: ", arr1);
    printArray(i, arr1, n);

    // For Array2
    int j, m, arr2[m];
    //  Get the user input for the particular range for the array1
    printf("\n\nEnter the size of the array2: ");
    scanf("%d", &m);

    // If we type a negative range then show the error message
    if (m <= 0)
    {
        printf("Invalid size, Please enter a positive size for range.\n");
        return 1;
    }

    // Get the user input for the each element of the array
    printf("Enter the element of the array2:\n");
    for (j = 0; j < m; j++)
    {
        printf("Enter element %d: ", j + 1);
        scanf("%d", &arr2[j]);
    }

    // Print the entered array
    printf("Entered array2[]: ", arr2);
    printArray(j, arr2, m);

    mergeSortArrays(arr1, n, arr2, m);

    // Printing the merged arrays
    printf("Merged array1[]: ");
    int a;
    for (a = 0; a < n + m; a++)
    {
        printf("%d ", arr1[a]);
    }
    // printArray(0, arr1, n);
    printf("\n");

    // int b;
    // printf("Merged array2[]: ");
    // for (b = 0; b < m; b++)
    // {
    //     printf("%d ", arr2[b]);
    // }
    // // printArray(0, arr2, m);
    // printf("\n");
    return 0;
}
