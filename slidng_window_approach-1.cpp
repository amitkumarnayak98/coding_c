#include <stdio.h>

int main() {
    int n, targetSum;

    // Get user input for the range
    printf("Enter the range (up to which number): ");
    scanf("%d", &n);

    // Validate input to ensure it's not negative
    if (n <= 0) {
        printf("Please enter a positive number for the range.\n");
        return 1;  // Exit with an error code
    }

    // Get user input for the target sum
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    // Define an array with size n
    int numbers[n];

    // Initialize the array with numbers from 1 to n
    for (int i = 0; i < n; ++i) {
        numbers[i] = i + 1;
    }

    // Sliding window approach
    int start = 0, end = 0, currentSum = 0;

    while (end < n) {
        currentSum += numbers[end];

        while (currentSum > targetSum && start <= end) {
            currentSum -= numbers[start];
            start++;
        }

        if (currentSum == targetSum) {
            printf("First and last numbers contributing to the target sum (%d): %d %d\n", targetSum, numbers[start], numbers[end]);
            return 0;  // Exit the program with success
        }

        end++;
    }

    // If no subarray is found, print an array consisting only of -1
    printf("-1\n");

    return 0;
}
