#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function to implement simple calculator using switch statement
void calculate(double num1, double num2, char op)
{
    double result;
    int valid = 1; // Flag to check if operation is valid

    // Switch case
    switch (op)
    {
        case '+':
            result = num1 + num2;
            break;
        
        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            if (num2 == 0)
            {
                printf("Error: Division by zero is not possible.\n");
                valid = 0;
                break;
            }
            result = num1 / num2;
            break;

        case 'l':
            if (num1 <= 0 || num2 <= 1)
            {
                printf("Error: Invalid operand(s) for logarithm.\n");
                valid = 0;
                break;
            }
            result = log(num1) / log(num2);
            break;

        case '^':
            if ((num1 == 0 && num2 <= 0) || (num1 < 0 && trunc(num2) != num2))
            {
                printf("Error: Invalid operand(s) for power operation.\n");
                valid = 0;
                break;
            }
            result = pow(num1, num2);
            break;

        default:
            printf("Error: Invalid operator entered.\n");
            valid = 0;
            break;
    }

    if (valid)
    {
        printf("Result = %.2f\n", result);
    }
}

int main()
{
    char op;
    double num1, num2;
    size_t attempts;

    // Handle the first operand input
    attempts = 0; // Reset attempts counter for the first operand
    while (attempts < 3)
    {
        printf("Enter the first operand: ");
        if (scanf(" %lf", &num1) == 1) break; // Valid input, break loop
        printf("Invalid input. Please enter a valid number.\n");
        attempts++;
        while (getchar() != '\n');  // Clear the input buffer
    }

    if (attempts == 3)
    {
        printf("Too many incorrect attempts. Terminating the program.\n");
        return 1; // Exit the program
    }

    // Handle the second operand input
    attempts = 0; // Reset attempts counter for the second operand
    while (attempts < 3)
    {
        printf("Enter the second operand: ");
        if (scanf(" %lf", &num2) == 1) break; // Valid input, break loop
        printf("Invalid input. Please enter a valid number.\n");
        attempts++;
        while (getchar() != '\n');  // Clear the input buffer
    }

    if (attempts == 3)
    {
        printf("Too many incorrect attempts. Terminating the program.\n");
        return 1; // Exit the program
    }

    // Read the operator
    printf("Enter an operator (+, -, *, /, l for log, ^ for power): ");
    scanf(" %c", &op);  // Added a space before %c to ignore any leading whitespace

    calculate(num1, num2, op);

    return 0;
}