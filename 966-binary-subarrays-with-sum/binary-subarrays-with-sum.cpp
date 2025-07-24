class Solution {
public:
    /**
     * Finds the number of non-empty subarrays that sum to a given target
     * (goal).
     *
     * @param nums A binary array (only 0s and 1s)
     * @param goal The target sum for subarrays
     * @return The total number of subarrays with sum equal to goal
     */
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefix_zeros = 0; // Tracks number of leading zeros in the current valid window
        int window_sum = 0; // Current sum of the sliding window
        int count = 0; // Result: number of subarrays with sum equal to goal

        int i = 0, j = 0; // i = start of window, j = end of window

        // Extend the window by moving 'j' (right pointer)
        while (j < nums.size()) {
            window_sum += nums[j]; // Add the current number to the window sum

            // Shrink the window from the left if:
            //  - window_sum exceeds the goal
            //  - or leading zeros can be removed (for multiple subarrays
            //  starting with 0)
            while (i < j && (nums[i] == 0 || window_sum > goal)) {
                // If we hit a 1, reset prefix_zeros as we can't skip over it
                if (nums[i] == 1) {
                    prefix_zeros = 0;
                } else {
                    // Count how many zeros we can skip from the front
                    prefix_zeros += 1;
                }

                // Remove nums[i] from window_sum and move the window forward
                window_sum -= nums[i];
                i++;
            }

            // If the current window sum matches the goal,
            // count the subarrays:
            // - one starting at i
            // - plus each of the prefix_zeros as individual subarrays
            if (window_sum == goal) {
                count += 1 + prefix_zeros;
            }

            // Move the right end of the window forward
            j++;
        }

        return count;
    }
};
