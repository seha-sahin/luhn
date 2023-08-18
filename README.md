**Luhn's algorithm**

This exercise is part of CS50's Introduction to Computer Science - Problem Set 1, that is the implementation of the algorithm invented by Hans Peter Luhn of IBM, which is commonly used to syntactically check credit and debit card numbers for validation prior to database lookup.

Luhn's algorithm determines whether or not a credit card number is valid. For a given credit card number:
- Double the value of every other digit from right to left, beginning with the second to last digit.
- Add the digits of the results of Step 1 to the remaining digits in the credit card number.
- If the result mod 10 is equal to 0, the number is valid. If the result mod 10 is not equal to 0, the validation fails.

Sources:
Credit - CS50x 2023: https://cs50.harvard.edu/x/2023/psets/1/credit/
Special Pattern Tests - IBM Documentation: https://www.ibm.com/docs/en/guardium/11.3?topic=policies-special-pattern-tests
