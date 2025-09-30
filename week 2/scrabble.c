#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet (A → 0, B → 1, …, Z → 25)
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Declaration of the function that calculates the score of a word
int compute_score(string word);

int main(void)
{
    // Ask both players to enter their words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute scores for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Compare scores and print the result
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n"); // End of the program
    }

    return 0;
}

// Function that calculates the score of a word
int compute_score(string word)
{
    int score = 0; // start with zero points

    // Loop through each character in the word
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char c = word[i]; // Get the current character

        if (isupper(c)) // Check if the character is uppercase
        {
            // Calculate the index (A=0, B=1, ..., Z=25) and add the corresponding points
            score += POINTS[c - 'A'];
        }
        else if (islower(c))
        {
            // Calculate the index (a = 0, b = 1, ...)
            score += POINTS[c - 'a'];
        }
        // Ignore non-letter characters (like numbers or symbols)
    }

    return score; // Return the total score
}
