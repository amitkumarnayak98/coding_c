#include <stdio.h>
#include <ctype.h> // for isdigit() function

#define MAX 100 // Maximum size of the stack

// Global variables for stack
int stack[MAX];
int top = -1; // Initialize top of the stack

// Function to push element onto the stack
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

// Function to pop element from the stack
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int value = stack[top];
    top--;        // Decrement top
    return value; // Return the popped value
}

// Function to evaluate to the postfix expression
int evaluatePostfix(char exp[])
{
    int i;

    // Traverse the postfix expression
    for (i = 0; exp[i] != '\0'; i++)
    {
        // If the character is a number, push it to the stack
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0'); // Convert char to int and push
        }
        else
        {
            // If the charater is an operator, pop two elements from stack, perform the operation, and push the result back
            int operand2 = pop();
            int operand1 = pop();

            // Perform the operation based on the operator
            switch (exp[i])
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            default:
                printf("Invalid operator encountered\n");
                return -1;
            }
        }
    }

    return pop(); // The final result will be the last remaining element in the stack
}

int main()
{
    char postfix[MAX];

    // Input the postfix expression from the user
    printf("Enter a postfix expression (e.g., 231*+9-): ");
    scanf("%s", postfix);

    // Evaluate the postfix expression and print the result
    int result = evaluatePostfix(postfix);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}