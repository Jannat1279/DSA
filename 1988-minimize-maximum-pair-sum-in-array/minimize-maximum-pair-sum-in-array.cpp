class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // Step 1: Sort the array to easily form pairs from smallest and largest values
        sort(nums.begin(), nums.end());

        // Two-pointer approach: one from start (i), one from end (j)
        int i = 0, j = nums.size() - 1;

        // Variable to track the maximum pair sum
        int maxResult = 0;

        // Step 2: Pair smallest element with largest, move inward
        while (i < j) {
            // Current pair sum
            int sum = nums[i] + nums[j];

            // Update the maximum result so far
            maxResult = max(sum, maxResult);

            // Move pointers inward to form next pair
            i++;
            j--;
        }

        // Step 3: Return the minimized maximum pair sum
        return maxResult;
    }
};
