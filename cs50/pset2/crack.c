// Cracks passwords using crypt
// Compile: clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wshadow crack.c -lcrypt -lcs50 -lm -o crack
// Usage: ./crack hash

#define _XOPEN_SOURCE
#include <stdio.h>
#include <cs50.h>
#include <string.h>     // strcmp()
#include <unistd.h>     // crypt()

void crack();

int main(int argc, char *argv[])
{
    // Make sure there is only 1 argument
    switch (argc)
    {
        case 1:
            printf("Usage: ./crack hash\n");
            return 1;

        case 2:
            break;

        default:
            printf("Usage: ./crack hash\n");
            return 1;
    }

    // Assign argument as 'hash'
    string hash = argv[1];

    crack(hash);
}

void crack(string hash)
{
    string salt = "50";
    char alpha[52] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
        'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
        'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };

    bool cracked = false;

    // Cycle through all possible 1 - 4 letter keys
    for (int i = 0; i < 52; i++)
    {
        if (cracked)
        {
            break;
        }

        // Test keys: a - Z
        char one_letter_key[2] = {
            alpha[i], '\0'
        };

        // If 'hash' and hash generated from the key are the same
        if (strcmp(hash, crypt(one_letter_key, salt)) == 0)
        {
            // You found the password!
            printf("%s\n", one_letter_key);
            cracked = true;
        }

        for (int j = 0; j < 52; j++)
        {
            if (cracked)
            {
                break;
            }

            // Test keys: aa - ZZ
            char two_letter_key[3] = {
                alpha[i], alpha[j], '\0'
            };

            if (strcmp(hash, crypt(two_letter_key, salt)) == 0)
            {
                printf("%s\n", two_letter_key);
                cracked = true;
            }

            for (int k = 0; k < 52; k++)
            {
                if (cracked)
                {
                    break;
                }

                // Test keys: aaa - ZZZ
                char three_letter_key[4] = {
                    alpha[i], alpha[j], alpha[k], '\0'
                };

                if (strcmp(hash, crypt(three_letter_key, salt)) == 0)
                {
                    printf("%s\n", three_letter_key);
                    cracked = true;
                }

                for (int l = 0; l < 52; l++)
                {
                    if (cracked)
                    {
                        break;
                    }

                    // Test keys: aaaa - ZZZZ
                    char four_letter_key[5] = {
                        alpha[i], alpha[j], alpha[k], alpha[l], '\0'
                    };

                    if (strcmp(hash, crypt(four_letter_key, salt)) == 0)
                    {
                        printf("%s\n", four_letter_key);
                        cracked = true;
                    }
                }
            }
        }
    }
}

/*
    How to obtain a hash:
    crypt(key, salt)

    Example:
    crypt("rofl", "50");    // returns 50fkUxYHbnXGw

    User        Hash            Pass/Key
    ------------------------------------
    andi        50.jPgLzVirkc   hi
    jason       50YHuxoCN9Jkc   JH
    malan       50QvlJWn2qJGE   NOPE
    mzlatkova   50CPlMDLT06yY   ha
    patrick     50WUNAFdX/yjA   Yale
    rbowden     50fkUxYHbnXGw   rofl
    summer      50C6B0oz0HWzo   FTW
    stelios     50nq4RV/NVU0I   ABC
    wmartin     50vtwu4ujL.Dk   haha
    zamyla      50i2t3sOSAZtk   lol
*/