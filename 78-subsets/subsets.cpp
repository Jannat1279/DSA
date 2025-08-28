class Solution {
public:

    // Recursion approach to generate all subsets
    vector<vector<int>> ans; // Stores all subsets

    // Recursive helper function
    // nums -> input array
    // i    -> current index in nums
    // temp -> stores the current subset being formed
    void sub(vector<int>& nums, int i, vector<int> temp) {
        // Base Case: if we reach the end of nums, add the current subset
        if (i == nums.size()) {
            ans.push_back(temp); // Store the subset
            return;
        }

        // Choice 1: Include nums[i] in the current subset
        temp.push_back(nums[i]);  
        sub(nums, i + 1, temp);

        // Backtrack: remove nums[i] and explore subsets without it
        temp.pop_back();

        // Choice 2: Exclude nums[i] from the current subset
        sub(nums, i + 1, temp);
    }

    // Main function
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;       // Temporary subset (initially empty)
        sub(nums, 0, temp);     // Start recursion from index 0
        return ans;             // Return all subsets
    }
};
