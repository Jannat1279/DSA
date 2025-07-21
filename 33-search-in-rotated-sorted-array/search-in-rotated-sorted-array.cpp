class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, end = n - 1;
        while (s <= end) {
            int mid = (s + end) / 2;
            if (nums[mid] == target)
                return mid;
            // left half is sorted
            if (nums[s] <= nums[mid]) {
                if (nums[mid] > target && target >= nums[s]) {
                    end = mid - 1;
                }

                else {
                    s = mid + 1;
                }
            } 
            // right half is sorted
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    s = mid + 1;
                }

                else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

/*
Example:
Input:
nums = [4, 5, 6, 7, 0, 1, 2]
target = 0

🧮 Step-by-Step Execution:
Initial:
s = 0, end = 6

✅ Iteration 1:
mid = (0 + 6)/2 = 3
nums[mid] = 7
Left half [4, 5, 6, 7] is sorted (nums[s] <= nums[mid])
Check if target (0) is in this range:
nums[s] = 4 <= target = 0 <= nums[mid] = 7 → ❌ False
So, move to the right half: s = mid + 1 = 4

✅ Iteration 2:
s = 4, end = 6
mid = (4 + 6)/2 = 5
nums[mid] = 1
Left half [0, 1] is sorted (nums[s] <= nums[mid])
Check if target (0) is in this range:
nums[s] = 0 <= target = 0 <= nums[mid] = 1 → ✅ True
So, search left: end = mid - 1 = 4

✅ Iteration 3:
s = 4, end = 4
mid = 4
nums[mid] = 0 → ✅ Target found!

✅ Final Output:
4
*/
