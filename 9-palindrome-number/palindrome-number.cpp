class Solution {
public:
    bool isPalindrome(int x) {
        long long r, rev = 0;      // r stores last digit, rev stores reversed number
        long long temp = x;        // Copy original number to preserve x for comparison

        // Step 1: Reverse the number
        while (temp > 0) {
            r = temp % 10;         // Get the last digit
            rev = rev * 10 + r;    // Append last digit to reversed number
            temp = temp / 10;      // Remove last digit
        }

        // Step 2: Compare original number with reversed
        return (rev == x);         // Return true if palindrome, false otherwise
    }
};
/*
Initial: x = 121, temp = 121, rev = 0

Iteration 1:
r = 121 % 10 = 1
rev = 0 * 10 + 1 = 1
temp = 121 / 10 = 12

Iteration 2:
r = 12 % 10 = 2
rev = 1 * 10 + 2 = 12
temp = 12 / 10 = 1

Iteration 3:
r = 1 % 10 = 1
rev = 12 * 10 + 1 = 121
temp = 1 / 10 = 0
Loop ends (temp == 0)

Now compare:

rev == x → 121 == 121 → true ✅

*/
