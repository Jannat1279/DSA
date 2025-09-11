class Solution {
public:
    int t[1001][1001];  // DP memoization table (initialized with -1)
                        // t[m][n] stores the LCS length of text1[0..m-1] and text2[0..n-1]

    // Recursive function with memoization to compute LCS
    int LCS(string& text1, string text2, int m, int n) {
        // Base case: if any string is empty, LCS length is 0
        if (m == 0 || n == 0)
            return t[m][n] = 0;

        // If already computed, return from memo table
        if (t[m][n] != -1)
            return t[m][n];

        // If last characters match, they are part of LCS
        if (text1[m - 1] == text2[n - 1])
            return t[m][n] = 1 + LCS(text1, text2, m - 1, n - 1);

        // Otherwise, take the max by excluding either last char of text1 or text2
        return t[m][n] = max(LCS(text1, text2, m - 1, n), LCS(text1, text2, m, n - 1));
    }

    // Main function that initializes DP table and calls recursive function
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // Initialize DP table with -1
        memset(t, -1, sizeof(t));

        // Call recursive helper
        return LCS(text1, text2, m, n);
    }
};
