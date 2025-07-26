class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max=nums[0], max_so_far=nums[0];
        for(int i=1;i<nums.size();i++){
            // A decision is made whether to add the given element in the current subarray or start a new one.
            curr_max=max((curr_max+nums[i]),nums[i]);
            // max is updated further
            max_so_far=max(curr_max, max_so_far);
        }
        return max_so_far;
    }
};

/* TC - O(n)
 SC - O(1)
 
 Example:
 vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
| j | nums [j] | curr_max = max(nums [j], curr_max + nums [j])   | max_so_far = max(max_so_far, curr_max)      |
| - | -------- | ----------------------------------------------- | ------------------------------------------- |
| 1 | 1        | max(1, -2+1) = 1                                | max(-2, 1) = 1                              |
| 2 | -3       | max(-3, 1-3) = -2                               | max(1, -2) = 1                              |
| 3 | 4        | max(4, -2+4) = 4                                | max(1, 4) = 4                               |
| 4 | -1       | max(-1, 4-1) = 3                                | max(4, 3) = 4                               |
| 5 | 2        | max(2, 3+2) = 5                                 | max(4, 5) = 5                               |
| 6 | 1        | max(1, 5+1) = 6                                 | max(5, 6) = 6                               |
| 7 | -5       | max(-5, 6-5) = 1                                | max(6, 1) = 6                               |
| 8 | 4        | max(4, 1+4) = 5                                 | max(6, 5) = 6                               |

 
 */
