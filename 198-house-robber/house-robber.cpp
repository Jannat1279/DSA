class Solution {
public:
    // Memoization array to store intermediate results
    int t[101];

    // Recursive function to calculate the maximum amount that can be robbed
    // starting from house index 'i' up to house 'n'
    int solve(vector<int>& nums, int i, int n) {
        // Base case: If index exceeds or equals number of houses, return 0
        if (i >= n)
            return 0;

        // If result is already computed, return it (memoization)
        if (t[i] != -1)
            return t[i];

        // Choice 1: Steal from current house and move to the house after next
        int steal = nums[i] + solve(nums, i + 2, n);

        // Choice 2: Skip current house and move to the next house
        int skip = solve(nums, i + 1, n);

        // Store and return the maximum of both choices
        return t[i] = max(steal, skip);
    }

    // Main function to be called with the input list of houses
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Initialize memoization array with -1 (indicating uncomputed states)
        memset(t, -1, sizeof(t));

        // Start solving from the 0th house
        return solve(nums, 0, n);
    }
};
