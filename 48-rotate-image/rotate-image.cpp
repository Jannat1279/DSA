#include <bits/stdc++.h>
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m =matrix.size(); // Get the size of the matrix (number of rows/columns)

        // Step 1: Transpose the matrix (swap across the diagonal)
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                // Swap elements across the main diagonal
                swap(matrix[i][j], matrix[j][i]);
            }

            // Step 2: Reverse each row to complete the 90° clockwise rotation
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};