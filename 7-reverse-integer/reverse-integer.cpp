class Solution {
public:
    int reverse(int x) {
        int temp = x;     // Store the original number in a temp variable
        int rev = 0;      // This will hold the reversed number

        // Loop until all digits are processed
        while (temp != 0) {
            int r = temp % 10;  // Extract the last digit

            // Check for overflow/underflow before multiplying by 10
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
                return 0;  // Return 0 if reversing would cause overflow

            rev = rev * 10 + r;  // Append the digit to the reversed number
            temp /= 10;          // Remove the last digit from temp
        }

        // Return the reversed number (signed)
        return rev;
    }
};

/*
Example:
int reverse(int x)
🔢 Example:
x = -123
We want to reverse the digits of x and return -321.

✅ Step-by-Step Execution:
Initial values:
temp = -123
rev = 0

1st iteration:
r = temp % 10 = -123 % 10 = -3
rev = rev * 10 + r = 0 * 10 + (-3) = -3
temp = temp / 10 = -123 / 10 = -12

2nd iteration:
r = -12 % 10 = -2
rev = -3 * 10 + (-2) = -30 + (-2) = -32
temp = -12 / 10 = -1

3rd iteration:
r = -1 % 10 = -1
rev = -32 * 10 + (-1) = -320 + (-1) = -321
temp = -1 / 10 = 0 → loop ends

✅ Final Output:
return -321
*/
