class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstCol = false;
        int m = matrix.size(), n = matrix[0].size();

        // Step 1: Check if first row and first column have any zeros
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) firstCol = true;
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) firstRow = true;
        }

        // Step 2: Use first row and column to mark zeros
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark the row
                    matrix[0][j] = 0; // Mark the column
                }
            }
        }

        // Step 3: Set cells to 0 based on markers in first row/column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 4: Zero the first row if needed
        if (firstRow) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 5: Zero the first column if needed
        if (firstCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
/*
matrix = [
  [1, 1, 1],
  [1, 0, 1],
  [1, 1, 1]
]
First row: [1, 1, 1] → no zero → firstRow = false
First column: 1, 1, 1 → no zero → firstCol = false

Now we check the rest of the matrix from i = 1 and j = 1 onward.

We find matrix[1][1] == 0

matrix[1][0] = 0; // mark the row
matrix[0][1] = 0; // mark the column

[
  [1, 0, 1],
  [0, 0, 1],
  [1, 1, 1]
]
Since firstRow = false and firstCol = false, we do nothing here.

Final Output Matrix
[
  [1, 0, 1],
  [0, 0, 0],
  [1, 0, 1]
]
*/
