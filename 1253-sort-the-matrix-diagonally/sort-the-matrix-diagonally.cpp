class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // Map: key = (i - j), value = elements of that diagonal
        map<int, vector<int>> mp;

        // Step 1: Collect elements by their diagonals
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }

        // Step 2: Sort each diagonal in descending order
        // (so we can pop from back later while filling matrix)
        for (auto& it : mp) {
            sort(it.second.rbegin(), it.second.rend());
        }

        // Step 3: Refill the matrix with sorted diagonals
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = mp[i - j].back(); // take the smallest available
                mp[i - j].pop_back();         // remove it from diagonal
            }
        }

        return mat; // Sorted matrix
    }
};
