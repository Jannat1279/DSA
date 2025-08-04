class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minL = n + 1; // Initialize minL to a value larger than any possible subarray length
        int sum = 0;      // This will hold the current window sum
        int i = 0, j = 0; // i is the window's start, j is the window's end

        // Move the right end of the window forward
        while (j < n) {
            sum += nums[j]; // Add the current element to the window sum

            // Shrink the window from the left as long as the sum is >= target
            while (sum >= target) {
                minL = min(minL, j - i + 1); // Update the minimum length found
                sum -= nums[i]; // Remove the leftmost element from the window
                i++;            // Move the window start to the right
            }
            j++; // Expand the window to include the next element
        }

        // If no valid subarray was found, return 0; otherwise, return minL
        return (minL == n + 1) ? 0 : minL;
    }
};
