#include <stdio.h>
#include <math.h>

// Function Declaration
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);

int main() {
    char operator;
    double num1, num2, result;

    // Input
    printf("Enter an operator (+, -, *, /, ^): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    // Calculation
    switch(operator) {
        case '+':
        result = add(num1, num2);
        break;

        case '-':
        result = subtract(num1, num2);
        break;

        case '*':
        result = multiply(num1, num2);
        break;

        case '/':
        if (num2 != 0) {
            result = divide(num1, num2);
        } else {
            printf("Error: Division by zero is not allowed.\n");
            return 1; // Exit with an error code
        }
        break;

        case '^':
        result = power(num1, num2);
        break;

        default:
        printf("Error: Invalid operator.\n");
        return 1; // Exit with an error code

    }

    // Output
    printf("Result: %.2f\n", result);

    return 0;
}

// Function definitions

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}
