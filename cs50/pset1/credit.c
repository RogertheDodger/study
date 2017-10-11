// Determines whether a provided credit card number is valid according to Luhn’s algorithm.

#include <stdio.h>
#include <cs50.h>

int get_length();
void verify();

int main(void)
{
    printf("What is your credit card number?\n");
    long long int card_num = get_long_long();

    verify(card_num);
}

void verify(long long int n)
{
    int sum = 0;
    int position = 0;
    int first_digit = 0;
    int first_two_digits = 0;
    int length = get_length(n);

    for (int i = length; i > 0; i--)
    {
        if (i == 2)
        {
            first_two_digits = n;
        }
        else if (i == 1)
        {
            first_digit = n;
        }

        position--;

        int digit = n % 10;

        if (position % 2 == 0)
        {
            digit *= 2;
            sum += digit % 10;
            digit /= 10;
            sum += digit % 10;
        }
        else
        {
            sum += digit;
        }

        n /= 10;
    }

    // if the last digit of 'sum' is 0
    if (sum % 10 == 0)
    {
        if (first_two_digits == 0)
        {
            printf("INVALID\n");
        }
        else if (first_digit == 4)
        {
            if (length == 13 || length == 16)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            switch (first_two_digits)
            {
                case 34:
                case 37:
                    if (length == 15)
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    break;

                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                    if (length == 16)
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                    break;
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_length(long long int n)
{
    if (n >= 1000000000000000)
    {
        return 16;
    }
    else if (n >= 100000000000000)
    {
        return 15;
    }
    else if (n >= 1000000000000)
    {
        return 13;
    }
    else
    {
        return 0;
    }
}
