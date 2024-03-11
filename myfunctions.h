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

#endif