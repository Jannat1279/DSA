class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        // Initialize result as n (the position after the last element).
        // This will be the insertion index if target is greater than all elements.
        int result = n;

        // Binary search to find the first index where nums[mid] >= target
        while (low <= high) {
            int mid = (low + high) / 2;

            // If the middle element is greater than or equal to target,
            // it could be the insert position or even earlier.
            if (nums[mid] >= target) {
                result = mid;    // update the potential insert position
                high = mid - 1;  // move left to check if there's a better position
            } else {
                low = mid + 1;   // move right since nums[mid] < target
            }
        }

        return result;
    }
};

/*
Example:
vector<int> nums = {1, 3, 5, 6};
int target = 5;
We want to find the index where 5 should be inserted (or found) in the sorted array nums.

🔍 Initial Values:
n = 4
low = 0, high = 3 (indices of the array)
result = 4 (initially set to n)

🧠 Step-by-step Binary Search:
🟢 Iteration 1:
mid = (0 + 3) / 2 = 1
nums[mid] = nums[1] = 3
Since 3 < 5, we update low = mid + 1 = 2

🟢 Iteration 2:
mid = (2 + 3) / 2 = 2
nums[mid] = nums[2] = 5
Since 5 >= 5, we update:
result = mid = 2
high = mid - 1 = 1
Now, low (2) > high (1), so the loop stops.

✅ Final Output:
result = 2

This means the target 5 is found at index 2, which is correct.
*/
