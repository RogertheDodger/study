// Reports a user’s water usage, converting minutes spent in the shower to bottles of drinking water.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("1 minute shower == 12 bottles of water\n");
    printf("How long are your showers? (in minutes)\n");
    int minutes = get_int();

    printf("Minutes: %i\n", minutes);
    printf("Bottles: %i\n", minutes * 12);
}
