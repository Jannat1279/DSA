class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Get the number of rows (n) and columns (m)
        int n = matrix.size();
        int m = matrix[0].size();

        // Define the boundaries of the matrix
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;

        // Result vector to store the spiral order
        vector<int> ans;

        // Loop until the boundaries overlap
        while (top <= bottom && left <= right) {

            // Traverse from left to right along the top row
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;  // Move the top boundary down

            // Traverse from top to bottom along the right column
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;  // Move the right boundary to the left

            // Traverse from right to left along the bottom row (if within bounds)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;  // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left column (if within bounds)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;  // Move the left boundary to the right
            }
        }

        // Return the final spiral order traversal
        return ans;
    }
};
