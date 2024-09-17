#include <stdio.h>

int main()
{
    char str[100]; // Array to store the original string
    char rev[100]; // Array to store the reversal string
    int i, len = 0;

    // Step 1: Ask the user for a string
    printf("Enter a string: ");
    scanf("%s", str);

    // Step 2: Find the length of the string manually
    for (i = 0; str[i] != '\0'; i++)
    {
        len++;
    }

    // Step 3: Reverse the string
    for (i = 0; i < len; i++)
    {
        rev[i] = str[len - i - 1]; // Assign characters in reverse order
    }

    rev[len] = '\0'; // Null-terminate the reversed string

    // Step 4: Print the reversed string
    printf("Reversed string: %s\n", rev);

    return 0;
}