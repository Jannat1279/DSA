class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();   // m = number of rows, n = number of columns
        
        map<int, vector<int>> mp;      // Map to group elements by diagonals (key = i + j)
        vector<int> result;                      // Final result array

        // Step 1: Group elements by diagonals
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);  // Elements with same (i + j) belong to the same diagonal
            }
        }

        bool flip = true;   // Used to alternate reversing of diagonals (zig-zag order)

        // Step 2: Traverse diagonals in order
        for (auto& it : mp) {
            if (flip) {
                // Reverse current diagonal before adding (to match required diagonal order)
                reverse(it.second.begin(), it.second.end());
            }

            // Add diagonal elements to result
            for (int& num : it.second) {
                result.push_back(num);
            }

            // Alternate between reversed and normal order
            flip = !flip;
        }

        // Step 3: Return the traversal result
        return result;
    }
};
