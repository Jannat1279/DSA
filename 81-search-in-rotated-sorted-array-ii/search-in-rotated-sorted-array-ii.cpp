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

/*
Example:
Input: nums = [1, 0, 1, 1, 1], target = 0

Initial:
low = 0, high = 4
✅ 1st iteration:
mid = 2, nums[mid] = 1
nums[low] == nums[mid] == nums[high] == 1
🔁 Can't decide which part is sorted, so:
low++, high--  → low = 1, high = 3

✅ 2nd iteration:
mid = (1+3)/2 = 2, nums[mid] = 1
nums[low] = 0, nums[mid] = 1
Left half is sorted. Check if target (0) is in range:
0 <= 0 <= 1 → ✅
→ high = mid - 1 = 1

✅ 3rd iteration:
low = 1, high = 1, mid = 1, nums[mid] = 0 → target found!

✅ Output:
true
*/
