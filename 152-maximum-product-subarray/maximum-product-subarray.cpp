class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        // curr_max → maximum product ending at the current position
        // curr_min → minimum product ending at the current position 
        // (important for handling negative numbers)
        // max_so_far → stores the maximum product found so far
        int curr_max = nums[0];
        int curr_min = nums[0];
        int max_so_far = nums[0];

        // Iterate through the array starting from the second element
        for (int i = 1; i < n; i++) {
            // If the current number is negative, 
            // multiplying by curr_max would make it smaller and by curr_min could make it larger
            // So, we swap them before calculation
            if (nums[i] < 0) {
                swap(curr_max, curr_min);
            }

            // Update curr_max: either take the current number alone 
            // or extend the previous product
            curr_max = max(nums[i], curr_max * nums[i]);

            // Update curr_min similarly for the smallest product
            curr_min = min(nums[i], curr_min * nums[i]);

            // Update overall maximum product
            max_so_far = max(curr_max, max_so_far);
        }

        // Return the maximum product found
        return max_so_far;
    }
};

/*
Example:
nums = [2, 3, -2, 4]

Initialization
curr_max = 2      // max product ending here
curr_min = 2      // min product ending here
max_so_far = 2    // overall max product so far

i = 1 → nums[1] = 3
nums[i] is positive → no swap
curr_max = max(3, 2*3) = max(3, 6) = 6
curr_min = min(3, 2*3) = min(3, 6) = 3
max_so_far = max(6, 2) = 6
curr_max = 6, curr_min = 3, max_so_far = 6

i = 2 → nums[2] = -2
nums[i] is negative → swap curr_max and curr_min
curr_max = 3, curr_min = 6
curr_max = max(-2, 3 * -2) = max(-2, -6) = -2
curr_min = min(-2, 6 * -2) = min(-2, -12) = -12
max_so_far = max(-2, 6) = 6

curr_max = -2, curr_min = -12, max_so_far = 6
i = 3 → nums[3] = 4
nums[i] is positive → no swap
curr_max = max(4, -2*4) = max(4, -8) = 4
curr_min = min(4, -12*4) = min(4, -48) = -48
max_so_far = max(4, 6) = 6
curr_max = 4, curr_min = -48, max_so_far = 6
✅ Final Answer → max_so_far = 6
(Max product subarray is [2, 3] with product 6)


*/
