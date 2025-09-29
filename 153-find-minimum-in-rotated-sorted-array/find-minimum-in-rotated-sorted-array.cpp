// time - O(log n), space - O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        // Perform binary search to find the minimum element in a rotated sorted
        // array
        while (low <= high) {
            int mid = (low + high) / 2;

            // If the left half [low...mid] is sorted
            if (nums[low] <= nums[mid]) {
                // The smallest element in the left half is nums[low]
                ans = min(ans, nums[low]);

                // Eliminate the left half since the minimum cannot lie before
                // mid (inclusive)
                low = mid + 1;
            } else {
                // If right half [mid...high] is sorted, then nums[mid] could be
                // the minimum
                ans = min(ans, nums[mid]);

                // Eliminate the right half since the minimum must lie to the
                // left of mid
                high = mid - 1;
            }
        }

        return ans; // Return the minimum element found
    }
};
