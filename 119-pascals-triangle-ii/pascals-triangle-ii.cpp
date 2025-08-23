class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Create a 2D vector to store Pascal's triangle rows up to rowIndex
        vector<vector<int>> res(rowIndex+1);

        // Build Pascal's triangle row by row
        for(int i = 0; i < rowIndex+1; i++) {
            // Initialize each row with size (i+1), filled with 1
            res[i] = vector<int>(i+1, 1);

            // Fill in values for the inner elements of the row
            for(int j = 1; j < i; j++) {
                // Each element is the sum of two elements above it
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }

            // If we've reached the desired row, return it immediately
            if(i == rowIndex) return res[i];
        }

        // Safety return (though code always returns earlier)
        return {};
    }
};
