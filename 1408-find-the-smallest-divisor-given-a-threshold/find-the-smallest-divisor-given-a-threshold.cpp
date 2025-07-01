class Solution {
public:
    // Helper function to compute the total sum after dividing each element by 'threshold' and rounding up
    int sumByD(vector<int>& nums, int threshold) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // Equivalent to ceil(nums[i] / threshold) using integer math
            sum += (nums[i] + threshold - 1) / threshold;
        }
        return sum;
    }

    // Main function to find the smallest divisor such that the sumByD result is <= threshold
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        // Upper bound is the maximum element in the array
        int high = *max_element(nums.begin(), nums.end());

        // Binary search for the smallest divisor that keeps the sum within threshold
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the total sum with current divisor is within threshold, try smaller divisor
            if (sumByD(nums, mid) <= threshold) {
                high = mid - 1;
            }
            // Else, increase divisor to reduce the sum
            else {
                low = mid + 1;
            }
        }

        // 'low' is the smallest valid divisor found
        return low;
    }
};
