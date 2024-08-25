#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function for the game
int game(char you, char computer)
{
    // If it's a tie
    if (you == computer)
        return -1;

    // Determine result
    if ((you == 'r' && computer == 'p') || 
        (you == 'p' && computer == 's') || 
        (you == 's' && computer == 'r'))
        return 0; // Loss
    else
        return 1; // Win
}

char user_input()
{
    char you;

    // Prompt player for input
    printf("\nEnter r for ROCK, p for PAPER, s for SCISSORS, or q to QUIT: ");

    // Read the input
    scanf(" %c", &you);

    // Convert to lowercase
    you = tolower(you);

    // Check if input is valid
    return (you == 'r' || you == 'p' || you == 's' || you == 'q') ? you : 'i'; // 'i' for invalid input
}

int main()
{
    char you, computer;
    int result;
    int invalid_attempts = 0;

    // Seed the random number generator
    srand(time(NULL));

    do
    {
        // Stores the random number
        int n;

        // Obtain 3 numbers 0, 1, 2
        n = rand() % 3;

        // Assign rock, paper, and scissors
        computer = (n == 0) ? 'r' : (n == 1) ? 'p' : 's';

        // Get user input
        while (1)
        {
            you = user_input();

            if (you == 'i')
            {
                invalid_attempts++;
                printf("!INVALID INPUT!\n");
                
                if (invalid_attempts >= 3)
                {
                    printf("Too many invalid attempts. Quitting the game.\n");
                    return 0; // Terminate the program
                }

                printf("Please try again.");
            }
            else
            {
                invalid_attempts = 0;
                break; // Valid input received
            }
        }

        // If the user chooses to quit
        if (you == 'q')
        {
            printf("Quitting the game. Goodbye!\n");
            break;
        }

        // Function call to result
        result = game(you, computer);

        printf("You chose: %c, Computer chose: %c\n", you, computer);

        if (result == -1)
            printf("It's a TIE!\n");
        else if (result == 0)
            printf("You LOSE!\n");
        else
            printf("You WIN!\n");

    } while (1); // Loop indefinitely until 'q' is entered

    return 0;
}