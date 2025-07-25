class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize max_so_far and curr_max with the first element of the
        // array
        int max_so_far = nums[0];            // Stores the maximum subarray sum found so far
        int curr_max = nums[0]; // Stores the maximum subarray sum ending at the
                                // current index

        // Start from the second element and process till the end
        for (int j = 1; j < nums.size(); j++) {
            // Either start a new subarray from current element,
            // or extend the previous subarray by including nums[j]
            curr_max = max(nums[j], nums[j] + curr_max);

            // Update max_so_far if the current subarray has a greater sum
            max_so_far = max(curr_max, max_so_far);
        }

        // Return the overall maximum subarray sum
        return max_so_far;
    }
};

/*
Example:
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

| j | nums [j] | curr_max = max(nums[j], nums[j] + curr_max)     | max_so_far = max(curr_max, max_so_far)      |
| - | -------- | ----------------------------------------------- | ------------------------------------------- |
| 0 | -2       | curr_max = -2                                   | max_so_far = -2                             |
| 1 | 1        | curr_max = max(1, 1 + (-2)) = 1                 | max_so_far = max(1, -2) = 1                 |
| 2 | -3       | curr_max = max(-3, -3 + 1) = -2                 | max_so_far = max(1, -2) = 1                 |
| 3 | 4        | curr_max = max(4, 4 + (-2)) = 4                 | max_so_far = max(1, 4) = 4                  |
| 4 | -1       | curr_max = max(-1, -1 + 4) = 3                  | max_so_far = max(4, 3) = 4                  |
| 5 | 2        | curr_max = max(2, 2 + 3) = 5                    | max_so_far = max(4, 5) = 5                  |
| 6 | 1        | curr_max = max(1, 1 + 5) = 6                    | max_so_far = max(5, 6) = 6 ✅               |
| 7 | -5       | curr_max = max(-5, -5 + 6) = 1                  | max_so_far = max(6, 1) = 6                  |
| 8 | 4        | curr_max = max(4, 4 + 1) = 5                    | max_so_far = max(6, 5) = 6                  |

*/
