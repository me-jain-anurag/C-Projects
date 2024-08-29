#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6

struct WordWithHint
{
    char *word;
    char *hint;
};

int main()
{
    struct WordWithHint word_list[] =
    {
        { "geeksforgeeks", "Computer coding" },
        { "elephant", "A large mammal with a trunk" },
        { "pizza", "A popular Italian dish" },
        { "beach", "Sandy shore by the sea" },
        { "pseudomorbidity", "false death"},
        { "xylophone", "A musical instrument" },
        { "aardvark", "A nocturnal animal" },
        { "queue", "A line or sequence" },
        { "rhythm", "A strong, regular beat" },
        { "crypt", "An underground vault" },
    };

    srand(time(NULL));

    int answer = rand() % 10;

    const char *word = word_list[answer].word;
    const char *hint = word_list[answer].hint;

    printf("Welcome to Hangman!\n");
    printf("Hint: %s\n", hint);

    char guess;
    int tries = 0;
    size_t n = strlen(word);

    bool guessedLetters[26] = {false};
    char guessedWord[MAX_WORD_LENGTH] = {0};

    while (tries < MAX_TRIES && strcmp(guessedWord, word) != 0)
    {
        printf("\n\nEnter your guess: ");
        guess = tolower(getchar());
        while (getchar() != '\n'); // Clear the input buffer

        if (!isalpha(guess))
        {
            printf("Invalid input. Please enter a single alphabetic character.\n");
            continue;
        }

        if (guessedLetters[guess - 'a'])
        {
            tries++;
            printf("Letter already guessed.\nYou have %d tries left.\nTry again!", (MAX_TRIES - tries));
            continue;
        }

        guessedLetters[guess - 'a'] = true;
        bool flag = false;

        for (size_t i = 0; word[i] != '\0'; i++)
            if (guess == word[i])
            {
                guessedWord[i] = guess;
                flag = true;
            }
        
        for (size_t i = 0; word[i] != '\0'; i++)
        {
            if (guessedWord[i] != '\0')
                printf("%c ", guessedWord[i]);
            else
                printf("_ ");
        }

        if (!flag)
        {
            tries++;
            printf("\nWrong guess!");
        }

        if (strcmp(guessedWord, word) != 0)
            printf("\nYou have %d tries left.", (MAX_TRIES - tries));
    }

    if (strcmp(guessedWord, word) == 0)
        printf("\n\nCongratulations. You have guessed the word.\nYou Win!");
    else
        printf("\n\n#sedlyf\nYou lose.\nThe answer was %s.", word);
    
    return 0;
}