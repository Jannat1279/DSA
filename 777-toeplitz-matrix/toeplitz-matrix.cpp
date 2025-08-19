class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of columns

        // Traverse each cell of the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // For cells that are not in the first row or first column,
                // check if the current element is equal to the top-left diagonal element.
                if (i > 0 && j > 0 && matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false; // If mismatch is found, it's not a Toeplitz matrix
                }
            }
        }

        // If all diagonal elements matched, it's a Toeplitz matrix
        return true;
    }
};
