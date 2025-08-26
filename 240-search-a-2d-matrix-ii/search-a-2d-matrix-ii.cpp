class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();       // number of rows
        int m = matrix[0].size();    // number of columns

        // Start from the **top-right corner**
        int row = 0, col = m - 1;

        // Continue while we stay inside the matrix bounds
        while (row < n && col >= 0) {
            if (matrix[row][col] == target) {
                return true;  // Found the target
            } 
            else if (matrix[row][col] < target) {
                // Current element is too small, move down to the next row
                row++;
            } 
            else {
                // Current element is too large, move left to the previous column
                col--;
            }
        }

        // If we exit the loop, target was not found
        return false;
    }
};
