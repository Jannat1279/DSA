class Solution {
public:
    // Function to search for a target in a rotated sorted array with duplicates
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // If target is found at mid
            if (nums[mid] == target) {
                return true;
            }

            // If duplicates are present at low, mid, and high, we cannot decide the sorted part
            // So we shrink the range from both ends
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // If the left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target lies within the sorted left half
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else { // Target is in the right half
                    low = mid + 1;
                }
            }
            // Otherwise, the right half is sorted
            else {
                // Check if target lies within the sorted right half
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else { // Target is in the left half
                    high = mid - 1;
                }
            }
        }

        // Target not found
        return false;
    }
};
