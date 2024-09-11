// C Program to implement Snake and Ladder Game 
#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
// Function to roll a six-sided die 
int rolldie() {return rand() % 60 + 1; }
// Initiate players
int player1 = 0, player2 = 0;
// Function to print board
void showboard()
{
    size_t i;
    // Print board
    for (i = 100; i > 0; i--)
    {
        bool printed = false;
        if (player1 == i)
        {
            printf("#P1\t");
            printed = true;
        }
        if (player2 == i)
        {
            printf("#P2\t");
            printed = true;
        }
        if (!printed)
        {
            printf("%d\t", i);
        }

        if ((i - 1) % 10 == 0)
        {
            printf("\n");
        }
    }
}

int movePlayer(int currentPosition,int roll)
{
    int newPosition;
    newPosition = currentPosition + roll;

    if (newPosition > 100)
    {
        return currentPosition;
    }

    return newPosition;    
}

int main()
{
    int currentPlayer = 1;
    //char input;
    srand(time(NULL));

    while (1)
    {
        printf("\nPlayer %d, it's your turn to roll the die.\n", currentPlayer);
        printf("Press enter to continue.\n");
        //input = getchar();
        getchar();
        /*if (input != '\n')
        {
            printf("Invalid input entered. Please press enter.");
            continue;
        }*/
        int roll = rolldie();
        printf("You rolled a %d\n\n", roll);
        if (currentPlayer == 1)
        {
            player1 = movePlayer(player1, roll);
            showboard();
            if (player1 == 100)
            {
                printf("\nCongrats. Player 1 won!!\n");
                break;
            }
        }
        else
        {
            player2 = movePlayer(player2, roll);
            showboard();
            if (player2 == 100)
            {
                printf("\nCongrats. Player 2 won!!\n");
                break;
            }
        }
        
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}