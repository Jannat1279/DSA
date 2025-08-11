class Solution {
public:
    int t[501][501]; // DP table for memoization, t[i][j] stores minimum insertions for substring s[i..j]

    // Recursive function to find the minimum insertions needed to make s[i..j] a palindrome
    int solve(int i, int j, string &s) {
        // Base case: if i >= j, the substring is already a palindrome (0 or 1 character)
        if (i >= j)
            return 0;

        // If already computed, return stored result
        if (t[i][j] != -1)
            return t[i][j];

        // If the characters match, move both pointers inward without insertion
        if (s[i] == s[j])
            return solve(i + 1, j - 1, s);

        // If characters don't match:
        // We insert a character either at the start or at the end
        // and take the minimum insertions required from both options
        return t[i][j] = 1 + min(
            solve(i + 1, j, s), // Option 1: Insert matching char at the end
            solve(i, j - 1, s)  // Option 2: Insert matching char at the start
        );
    }

    // Main function to return the minimum number of insertions for the whole string
    int minInsertions(string s) {
        int n = s.length();

        // Initialize DP table with -1 (uncomputed state)
        memset(t, -1, sizeof(t));

        // Solve for the entire string
        return solve(0, n - 1, s);
    }
};
