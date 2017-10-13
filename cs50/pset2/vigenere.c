// Encrypts messages using Vigenere’s cipher.
// Usage: ./vigenere k

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

void encrypt();

int main(int argc, char *argv[])
{
    switch (argc)
    {
        case 1:
            printf("Usage: ./vigenere k\n");
            return 1;

        case 2:
            break;

        default:
            printf("Usage: ./vigenere k\n");
            return 1;
    }

    int arglen = strlen(argv[1]);

    for (int i = 0; i < arglen; i++)
    {
        if (isalpha(argv[1][i]) == false)
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    string keyword = argv[1];

    printf("plaintext: ");
    string message = get_string();

    encrypt(message, keyword);
}

void encrypt(string p, string k)
{
    int plen = strlen(p);
    int klen = strlen(k);
    int j = 0;

    printf("ciphertext: ");

    for (int i = 0; i < plen; i++)
    {
        if (islower(k[j % klen]))
        {
            if (islower(p[i]))
            {
                printf("%c", ((p[i] + k[j % klen] - 194) % 26) + 97);
                j++;
            }
            else if (isupper(p[i]))
            {
                printf("%c", ((p[i] + k[j % klen] - 162) % 26) + 65);
                j++;
            }
            else
            {
                printf("%c", p[i]);
            }
        }
        else if (isupper(k[i % klen]))
        {
            if (islower(p[i]))
            {
                printf("%c", ((p[i] + k[j % klen] - 162) % 26) + 97);
                j++;
            }
            else if (isupper(p[i]))
            {
                printf("%c", ((p[i] + k[j % klen] - 130) % 26) + 65);
                j++;
            }
            else
            {
                printf("%c", p[i]);
            }
        }
    }

    printf("\n");
}