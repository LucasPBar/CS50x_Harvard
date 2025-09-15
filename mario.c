#include<stdio.h>
#include<cs50.h>

void game(int height);

int main(void)
{
    // Input column size and check user-defined value
    int height;
    do
    {
        height = get_int("Change the height: ");
    }
    while (height < 1 || height > 8);
    game(height);
}

// Pyramid creation
void game(int height)
{
    for (int i = 1; i <= height; i++)
    {
        // Prints leading spaces
        for(int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Print blocks #
        for(int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}
