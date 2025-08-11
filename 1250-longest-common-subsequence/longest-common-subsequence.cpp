class Solution {
public:
    int t[1001][1001];
    int LCS(string& text1, string text2, int m, int n) {
        if (m == 0 || n == 0)
            return t[m][n] = 0;
        if (t[m][n] != -1)
            return t[m][n];
        if (text1[m - 1] == text2[n - 1])
            return t[m][n] = 1 + LCS(text1, text2, m - 1, n - 1);
        return t[m][n] = max(LCS(text1, text2, m - 1, n), LCS(text1, text2, m, n - 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        memset(t, -1, sizeof(t));
        return LCS(text1, text2, m, n);
    }
};