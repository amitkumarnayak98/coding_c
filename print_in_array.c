#include <stdio.h>

int main() {
	int n;
	
	//Get user input for the range
	printf("Enter the range (up to which number): ");
	scanf("%d", &n);

	//Validate input to ensure it's not negative
	if (n <= 0) {
		printf("Please enter a positive number for the range.\n");
	}

    //Define an array with size n
    int numbers[n];
    int i;
    //Initialize the array with numbers from 1 to n
    for (i = 0; i < n; ++i){
        numbers[i] = i + 1;
    }

    //Print the array elements
    printf("Array elements: ");
    for (i = 0; i < n; ++i){
        printf("%d ", numbers[i]);
    }

    return 0;
}
