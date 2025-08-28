class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;

        // Step 1: Find first decreasing element from right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = nums.size() - 1;

            // Step 2: Find just larger element on right and swap
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the right half
        reverse(nums.begin() + i + 1, nums.end());
    }
};

/*
Example:
nums=[1,2,3]

nums = [3, 2, 1]
Step 1
i = 1 → nums[1]=2, nums[2]=1 → 2 >= 1, so i = 0
nums[0]=3, nums[1]=2 → 3 >= 2, so i = -1
No pivot found (means array is descending).

Step 2
Skipped, because i = -1.

Step 3
Reverse entire array → [1, 2, 3].

✅ That’s the next permutation after [3,2,1].

*/
