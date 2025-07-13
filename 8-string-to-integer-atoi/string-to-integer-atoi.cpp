class Solution {
public:
    int myAtoi(string s) {
        // Edge case: empty string
        if (s.length() == 0)
            return 0;

        int i = 0;

        // Step 1: Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Remove the leading spaces by creating a substring
        s = s.substr(i);

        // Step 2: Set default sign to positive
        int sign = +1;

        // To store the result
        long ans = 0;

        // Step 3: Handle optional '+' or '-' sign
        if (s[0] == '-')
            sign = -1;

        // Constants for integer limits
        int MAX = INT_MAX;
        int MIN = INT_MIN;

        // Step 4: Start parsing digits (skip sign if present)
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        while (i < s.length()) {
            // Step 5: Break if non-digit is encountered
            if (!isdigit(s[i]))
                break;

            // Step 6: Convert char to digit and append to result
            ans = ans * 10 + (s[i] - '0');

            // Step 7: Check for overflow and clamp
            if (sign == -1 && -1 * ans < MIN)
                return MIN;
            if (sign == +1 && ans > MAX)
                return MAX;

            i++;
        }

        // Step 8: Return final result with sign applied
        return (int)(sign * ans);
    }
};