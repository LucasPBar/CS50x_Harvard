#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
bool is_valid_key(string key);
char substitute(char c, string key);

int main(int argc, string argv[])
{
    // Check for exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate the key
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Encrypt each character of the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", substitute(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

// Validate the substitution key
bool is_valid_key(string key)
{
    // Key must be 26 characters long
    if (strlen(key) != 26)
    {
        return false;
    }

    int letters[26] = {0};

    // Check each character in the key
    for (int i = 0; i < 26; i++)
    {
        // Key must contain only alphabetic characters
        if (!isalpha(key[i]))
        {
            return false;
        }

        // Convert character to uppercase index
        int index = toupper(key[i]) - 'A';

        // Check for duplicate letters
        if (letters[index] > 0)
        {
            return false;
        }

        letters[index]++;
    }

    return true;
}

// Substitute a character using the key
char substitute(char c, string key)
{
    // Substitute uppercase letters
    if (isupper(c))
    {
        return toupper(key[c - 'A']);
    }
    // Substitute lowercase letters
    else if (islower(c))
    {
        return tolower(key[c - 'a']);
    }
    // Leave non-alphabetic characters unchanged
    else
    {
        return c;
    }
}
