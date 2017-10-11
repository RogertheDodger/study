// Prints out a double half-pyramid of a specified height.

#include <cs50.h>
#include <stdio.h>

void spaces(int n);
void blocks(int n);

int main(void)
{
    int rows = -1;

    printf("How tall do you want your pyramid to be?\n");
    printf("(must be between 0 and 23)\n\n");

    while (rows < 0 || rows > 23)
    {
        printf("Height: ");
        rows = get_int();
    }

    for (int i = 0; i < rows; i++)
    {
        spaces(rows - (i + 1));
        blocks(i + 1);
        printf("\n");
    }
}

void spaces(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void blocks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }

    printf("  ");

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}
