#include <stdio.h>
#include <time.h>

// Method to calculate the maximum sum of elements of the array
int maxSubarraySum(int arr[], int N)
{
    int i;
    int max_sum = arr[0];
    int current_sum = arr[0];

    for (i = 1; i < N; i++)
    {
        // Update the current sum or start a new subarray
        current_sum = (current_sum + arr[i] > arr[i]) ? current_sum + arr[i] : arr[i];

        // Update the maximum sum if the current sum is greater
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

// Printing the array elements in a straight line. For Ex: 1 2 3 4 5
int printArray(int i, int arr[], int N)
{
    for (i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int N;

    // Get the user input for the range of the array
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    // If we type a negative number for range then show this message
    if (N <= 0)
    {
        printf("Invalid size, Please enter a positive size.\n");
        return 1;
    }

    int arr[N];
    int i;

    // Get the user input for the each element of the array
    printf("Enter the element of the array:\n");
    for (i = 0; i < N; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the entered array
    printf("\nEntered array[]: ", arr);

    printArray(i, arr, N);

    clock_t startTime = clock();

    int result = maxSubarraySum(arr, N);

    clock_t endTime = clock();

    printf("\n\nMaximum subarray sum is %d of elements ", result);

    printArray(i, arr, N);

    printf("which is a contiguous subarray");

    double executionTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    printf("\n\nExecution time: %f seconds", executionTime);

    return 0;
}
