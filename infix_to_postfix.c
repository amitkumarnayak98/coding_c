#include <stdio.h>
#include <ctype.h>  // for isalpha() and isdigit()
#include <string.h> // for strlen()

#define MAX 100 // Max size of the stack

// Stack for operators

char stack[MAX];
int top = -1;

// Function to push element to stack

void push(char x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = x;
    }
}

// Function to pop element from stack
char pop()
{
    if (top == -1)
    {
        return -1; // Stack is empty
    }
    else
    {
        return stack[top--];
    }
}

// Function to return precedence of operators
int precedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '^')
    {
        return 3;
    }
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char *infix)
{
    int i, k = 0;
    char postfix[MAX];

    for (i = 0; i < strlen(infix); i++)
    {
        char token = infix[i];

        // If the character is an operand (letter or digit), add it to the result

        if (isalnum(token))
        {
            postfix[k++] = token;
        }

        // if the character is '(', push it to the stack
        else if (token == '(')
        {
            push(token);
        }

        // if the character is ')', pop and output from the stack until '(' is found
        else if (token == ')')
        {
            while (stack[top] != '(')
            {
                postfix[k++] = pop();
            }
            pop(); // Pop '('
        }

        // Operator encountered
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(token))
            {
                postfix[k++] = pop();
            }
            push(token);
        }
    }

    // Pop the remaining operators from the stack
    while (top != -1)
    {
        postfix[k++] = pop();
    }

    // Null- terminate the postfix expression
    postfix[k] = '\0';

    // Print the postfix expression
    printf("Postfix Expression: %s\n", postfix);
}

// Main Function
int main()
{
    char infix[MAX];

    // Take input from the user
    printf("Enter an expression: ");
    scanf("%s", infix);

    // Convert infix to postfix and print the result
    infixToPostfix(infix);

    return 0;
}
