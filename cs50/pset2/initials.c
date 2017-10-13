// Converts a person's full name into initials.
// Usage: ./initials

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void to_initials();

int main(void)
{
    printf("What is your full name?\n");
    string name = get_string();

    to_initials(name);
}

void to_initials(string s)
{
    int length = strlen(s);
    char prev_char = 0;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(prev_char) == false)
        {
            if (isupper(s[i]))
            {
                printf("%c", s[i]);
            }
            else if (islower(s[i]))
            {
                printf("%c", s[i] - 32);
            }
        }

        prev_char = s[i];
    }

    printf("\n");
}