#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int countTriplets(int arr[], int N)
{
    qsort(arr, N, sizeof(int), compare); // Sort the array in ascending order
    int triplet_count = 0;
    int i;

    for (i = N - 1; i >= 2; i--)
    {
        int left = 0;
        int right = i - 1;

        while (left < right)
        {
            if (arr[left] + arr[right] == arr[i])
            {
                triplet_count++;
                left++;
                right--;
            }
            else if (arr[left] + arr[right] < arr[i])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return triplet_count;
}

int main()
{
    // Example usage:
    int N;

    // Get the user input for the range of the array
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    if (N <= 0)
    {
        printf("Invalid size, Please enter a positive size.\n");
        return 1;
    }
    int arr[N];
    int i;

    // Get the user input for the each element of the array
    printf("Enter the elements of the array:\n");
    for (i = 0; i < N; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the entered array
    printf("Entered array[]: ", arr);
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    // Measure the execution time
    clock_t startTime = clock();

    // Call the function or perform the computation
    int tripletsCount = countTriplets(arr, N);

    // Measure the execution time
    clock_t endTime = clock();

    printf("\nTriplets count: %d\n", tripletsCount);

    double executionTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds", executionTime);

    return 0;
}