#include <stdio.h>
#include <time.h>
#include "myfunctions.h"

int main()
{
    int N;

    // Get the user input for the range of the array
    printf("Enter the range of the array: ");
    scanf("%d", &N);

    // If we type a negative number for the range then show the below error message
    if (N <= 0)
    {
        printf("Invalid size, Please enter a positive size.\n");
        return 1;
    }

    int arr[N - 1];
    int i;

    // Get the user input for the each element of the array
    printf("Enter the element of the array:\n");

    for (i = 0; i < N - 1; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the entered array
    printf("\nEntered array[]: ", arr);
    // printArray function imported from constan file myfunctions.h
    printArray(i, arr, N - 1);

    clock_t startTime = clock();

    // MissingNumber function imported from constan file myfunctions.h
    int missingNumber = MissingNumber(arr, N - 1);

    clock_t endTime = clock();

    printf("\n\nMissing Number: %d\n", missingNumber);

    double executionTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    printf("\nExecution time: %f seconds", executionTime);
}