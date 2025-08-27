class Solution {
public:
    // To store all the valid combinations that sum up to the target
    vector<vector<int>> ans;

    // Recursive backtracking function to explore all combinations
    void solve(int i, vector<int> &candidates, vector<int> &temp, int target) {
        // If the target becomes 0, we found a valid combination
        if (target == 0) {
            ans.push_back(temp); // Store the current combination
            return;
        }

        // If the target becomes negative, the current path is invalid
        if (target < 0) {
            return;
        }

        if(i>=candidates.size())return;

        temp.push_back(candidates[i]);
        solve(i,candidates,temp,target-candidates[i]);
        temp.pop_back();
        solve(i+1,candidates,temp,target);
    }

    // Main function that initiates the recursive process
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear(); // Clear previous results if any
        vector<int> temp; // Temporary vector to store current combination
        solve(0, candidates, temp, target); // Start recursive backtracking
        return ans; // Return all valid combinations
    }
};