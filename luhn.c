#include <cs50.h>
#include <string.h>
#include <stdio.h>

// Declare helper functions for compiler
int c_to_i(char c);
int sum_multiplied(char number[], int digit_count);
int sum_non_multiplied(char number[], int digit_count);
int checksum(char number[], int digit_count);

int main(void)
{
    // Prompt user for card number
    long n = get_long("Number: ");

    // Write number to char list and compute number of digits
    char digits[256];
    sprintf(digits, "%ld", n);
    int digit_count = strlen(digits);

    // If checksum last digit 0, then check if:
    // Amex (15 digits and starts with 34 or 37)
    // Mastercard (16 digits and starts with 51, 52, 53, 54, 55)
    // Visa (13 or 16 digits and starts with 4)
    // ELSE invalid
    if (checksum(digits, digit_count) != 0)
    {
        if (digit_count == 15 && digits[0] == '3' && strchr("47", digits[1]) != NULL)
        {
            printf("AMEX\n");
        }
        else if (digit_count == 16 && digits[0] == '5' && strchr("12345", digits[1]) != NULL)
        {
            printf("MASTERCARD\n");
        }
        else if ((digit_count == 13 || digit_count == 16) && digits[0] == '4')
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
        printf("INVALID\n");
    }
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

// Compute checksum
int checksum(char number[], int digit_count)
{
    int checksum = sum_multiplied(number, digit_count);
    checksum += sum_non_multiplied(number, digit_count);
    return (checksum % 10 == 0);
}

// SOURCES
// Typecasting: https://www.geeksforgeeks.org/c-program-for-char-to-int-conversion

// Testing
    // printf("%d\n", digit_count);
    // printf("%c\n", digits[0]);
    // printf("%d\n", (int) (digits[0]));
    // printf("%d\n", c_to_i(digits[0]));
    // printf("%d\n", sum_multiplied(digits, digit_count));
    // printf("%d\n", sum_non_multiplied(digits, digit_count));
    // printf("%d\n", checksum(digits, digit_count));
