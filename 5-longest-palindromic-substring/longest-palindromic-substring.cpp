// Time Complexity: O(n^3) → O(n^2) for all substrings, O(n) for each palindrome check
class Solution {
public:

    // Function to check if the substring s[l...r] is a palindrome
    bool solve(string &s, int l, int r) {
        // Use two pointers to compare characters from both ends
        while (l <= r) {
            if (s[l] != s[r])  // Mismatch means not a palindrome
                return false;
            l++;
            r--;
        }
        return true; // All characters matched, it's a palindrome
    }

    // Main function to find the longest palindromic substring
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = INT_MIN;     // Stores length of the longest palindrome found
        int startingIndex = 0;    // Stores the starting index of the longest palindrome

        // Try every possible substring s[i...j]
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Check if substring from i to j is a palindrome
                if (solve(s, i, j)) {
                    // Update maxlen and startingIndex if this palindrome is longer
                    if (j - i + 1 > maxlen) {
                        startingIndex = i;
                        maxlen = j - i + 1;
                    }
                }
            }
        }

        // Return the longest palindromic substring
        return s.substr(startingIndex, maxlen);
    }
};

/*
Example:
s = "babad"

| Substring | Indices (i...j) | Is Palindrome? | Length                   |
| --------- | --------------- | -------------- | ------------------------ |
| "b"       | 0...0           | ✅ Yes         | 1                        |
| "ba"      | 0...1           | ❌ No          | -                        |
| "bab"     | 0...2           | ✅ Yes         | 3 ← ✅ longest so far    |
| "baba"    | 0...3           | ❌ No          | -                        |
| "babad"   | 0...4           | ❌ No          | -                        |
| "a"       | 1...1           | ✅ Yes         | 1                        |
| "ab"      | 1...2           | ❌ No          | -                        |
| "aba"     | 1...3           | ✅ Yes         | 3 ← same length as "bab" |
| "abad"    | 1...4           | ❌ No          | -                        |
| "b"       | 2...2           | ✅ Yes         | 1                        |
| "ba"      | 2...3           | ❌ No          | -                        |
| "bad"     | 2...4           | ❌ No          | -                        |
| "a"       | 3...3           | ✅ Yes         | 1                        |
| "ad"      | 3...4           | ❌ No          | -                        |
| "d"       | 4...4           | ✅ Yes         | 1                        |

*/
