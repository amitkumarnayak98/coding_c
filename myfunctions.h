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

inline void mergeSortArrays(int array1[], int rangeArray1, int array2[], int rangeArray2)
{
    int i = rangeArray1 - 1; // Index of last element in array1
    int j = rangeArray2 - 1; // Index of last element in array2

    int k = rangeArray1 + rangeArray2 - 1; // Index of last element in merged array

    // Merge the arrays from the end
    while (i >= 0 && j >= 0)
    {
        if (array1[i] > array2[j])
        {
            array1[k--] = array1[i--];
        }
        else
        {
            array1[k--] = array2[j--];
        }
    }

    // Copy remaining elements from array2 to array 1(if any)
    while (j >= 0)
    {
        array1[k--] = array2[j--];
    }

    // int i = 0, j = 0, k = 0;
    // int merged[rangeArray1 + rangeArray2];

    // // Merge the arrays while maintaining the sorted order
    // while (i < rangeArray1 && j < rangeArray2)
    // {
    //     if (array1[i] <= array2[j])
    //     {
    //         merged[k++] = array1[i++];
    //     }
    //     else
    //     {
    //         merged[k++] = array2[j++];
    //     }
    // }

    // // Copy remaining elements from array1
    // while (i < rangeArray1)
    // {
    //     merged[k++] = array1[i++];
    // }

    // while (j < rangeArray2)
    // {
    //     merged[k++] = array2[j++];
    // }

    // // Copy the merged array back to array1 and array2
    // int idx;
    // for (idx = 0; idx < rangeArray1; idx++)
    // {
    //     array1[idx] = merged[idx];
    // }

    // int idz;

    // for (idz = 0; idz < rangeArray2; idz++)
    // {
    //     array2[idx] = merged[rangeArray1 + idx];
    // }
}

#endif