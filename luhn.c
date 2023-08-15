#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

// Declare helper functions for compiler
int c_to_i(char c);
int sum_multiplied(char number[], int digit_count);
int sum_non_multiplied(char number[], int digit_count);
bool checksum(char number[], int digit_count);

// Typecasting: https://www.geeksforgeeks.org/c-program-for-char-to-int-conversion

int main(void)
{
    // Prompt user for card number
    long n = get_long("Number: ");

    // Write number to char list and compute number of digits
    char digits[256];
    sprintf(digits, "%ld", n);
    int digit_count = strlen(digits);

    // Print for testing
    printf("%d\n", digit_count);
    printf("%c\n", digits[0]);
    printf("%d\n", (int) (digits[0]));
    printf("%d\n", c_to_i(digits[0]));
    printf("%d\n", sum_multiplied(digits, digit_count));
    printf("%d\n", sum_non_multiplied(digits, digit_count));
    printf("%d\n", checksum(digits, digit_count));

    // If Amex (15 digits and starts with 34 or 37) or Mastercard (16 digits and starts with 51, 52, 53, 54, 55)
    // or Visa (13 or 16 digits and starts with 4)
        // Compute checksum
            // If checksum last digit 0 -> VALID
    // Else
        // CARD NOT VALID
    return 0;
}

// Typecast from char to int via ASCII conversion
int c_to_i(char c)
{
    return (((int) c) - 48);
}

// Compute sum of every other digit starting second-to-last
int sum_multiplied(char number[], int digit_count)
{
    int sum_multiplied = 0;
    int temp;
    for (int i = digit_count; i > 1; i -= 2)
    {
        temp = c_to_i(number[i - 2]) * 2;
        sum_multiplied += ((temp / 10) + (temp % 10));
    }
    return sum_multiplied;
}

// Compute sum of every other digit starting last
int sum_non_multiplied(char number[], int digit_count)
{
    int sum_non_multiplied = 0;
    for (int i = digit_count; i > 0; i -= 2)
    {
        sum_non_multiplied += c_to_i(number[i - 1]);
    }
    return sum_non_multiplied;
}

// Compute checksum - WIP to find out whether bool or int is better
bool checksum(char number[], int digit_count)
{
    int checksum = sum_multiplied(number, digit_count);
    checksum += sum_non_multiplied(number, digit_count);
    return (checksum % 10 == 0);
}
