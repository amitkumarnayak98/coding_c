#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

// Printing the array elements in a straight line. For Ex: 1 2 3 4 5
int printArray(int i, int arr[], int N)
{
    printf("[");
    for (i = 0; i < N; i++)
    {
        i == N - 1 ? printf("%d", arr[i]) : printf("%d, ", arr[i]);
    }
    printf("]");
}

// Finding out the missing number in series of numbers. For Ex: 1, 2, 3, 4
inline int MissingNumber(int arr[], int N)
{
    // int i;
    // int total = (N * (N + 1)) / 2; // Sum of the first N natural numbers
    // int arrSum = 0;

    // for (i = 0; i < N; i++)
    // {
    //     arrSum += arr[i];
    // }

    // return total - arrSum;
    int totalXor = 0;
    int arrXor = 0;
    int i;

    // XOR of all numbers between 1 to N
    for (i = 0; i <= N + 1; i++)
    {
        totalXor ^= i;
    }

    // XOR of array elements
    for (i = 0; i < N; i++)
    {
        arrXor ^= arr[i];
    }

    // XOR of the missing number
    return totalXor ^ arrXor;
}

int linearSearch(int arr[], int n, int target, int index)
{
    for (index = 0; index < n; index++)
    {
        if (arr[index] == target)
        {
            return index; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to perform bubble sort on the array
int bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap arr[j] and arr[j+]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform binary search
int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    // while (left <= right)
    // {
    // }

    if (left <= right)
    {
        int mid = left + ((right - left) / 2);

        // Check if target is present at mid
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            // If target greater, ignore left half
            return left = mid + 1;
        }
        else
        {
            // If target is smaller, ignore right half
            return right = mid - 1;
        }
    }
    // target is not present in the array
    return -1;
}

#endif