class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Edge case: if matrix is empty or has no columns, return false
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();     // total number of rows
        int cols = matrix[0].size();  // total number of columns

        // Treat the 2D matrix as a flattened sorted 1D array
        // Search range is [0, rows*cols - 1]
        int left = 0, right = rows * cols - 1;

        while (left <= right) {
            // Avoid overflow: use left + (right - left) / 2 instead of (left + right) / 2
            int mid = left + (right - left) / 2;

            // Map the 1D index `mid` back to 2D (row, col)
            int midVal = matrix[mid / cols][mid % cols];

            // Standard binary search logic
            if (midVal == target) {
                return true;  // target found
            } else if (midVal < target) {
                left = mid + 1;  // search right half
            } else {
                right = mid - 1; // search left half
            }
        }

        // If loop ends, target was not found
        return false;
    }
};
