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
