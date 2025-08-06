class Solution {
public:
    int m, n;

    // Recursive function to find minimum path sum from (i, j) to (m-1, n-1)
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& t) {
        // If we are at the destination cell, return its value
        if (i == m - 1 && j == n - 1)
            return t[i][j] = grid[i][j];

        // If already computed, return stored result
        if (t[i][j] != -1)
            return t[i][j];

        // If we are on the last row, we can only move right
        if (i == m - 1) {
            return t[i][j] = grid[i][j] + solve(grid, i, j + 1, t);
        }
        // If we are on the last column, we can only move down
        else if (j == n - 1) {
            return t[i][j] = grid[i][j] + solve(grid, i + 1, j, t);
        }

        // If we can move both right and down, take the minimum path sum
        int right = solve(grid, i, j + 1, t);
        int down = solve(grid, i + 1, j, t);
        return t[i][j] = grid[i][j] + min(right, down);
    }

    // Main function to initialize values and start recursion
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();             // Number of rows
        n = grid[0].size();          // Number of columns

        // Initialize DP table with -1 for memoization
        vector<vector<int>> t(m, vector<int>(n, -1));

        // Start from top-left corner (0, 0)
        return solve(grid, 0, 0, t);
    }
};
