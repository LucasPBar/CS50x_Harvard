#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for input text
    string text = get_string("Text: ");

    // Initialize counters for letters, words, and sentences
    int letters = 0;
    int words = 0;
    int sentences = 0;

    // Loop through each character in the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Count alphabetic characters as letters
        if (isalpha(text[i]))
        {
            letters++;
        }

        // Count spaces to estimate word boundaries
        if (text[i] == ' ')
        {
            words++;
        }

        // Count sentence-ending punctuation marks
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Add one to word count to include the last word
    words++;

    // Calculate average number of letters per 100 words
    float L = (float) letters / words * 100;

    // Calculate average number of sentences per 100 words
    float S = (float) sentences / words * 100;

    // Apply the Coleman-Liau index formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the reading grade level based on the index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
