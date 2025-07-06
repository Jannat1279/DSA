class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]!=0){
                // swap
                int temp=nums[left];
                nums[left]=nums[right];
                nums[right]=temp;
                left++;  // move the left pointer one ahead
            }
            // Here the non-zero elements move to the left which leave the 0 elements on the right i.e end.
        }
    }
};
// TC - O(n)
// SC - O(n)

/*
Example:
vector<int> nums = {0, 1, 0, 3, 12};

| Step | `right` | `left` | `nums`           | Action               |
| ---- | ------- | ------ | ---------------- | -------------------- |
| 1    | 0       | 0      | {0, 1, 0, 3, 12} | nums\[0] is 0 → skip |
| 2    | 1       | 0      | {1, 0, 0, 3, 12} | Swap 1 with 0        |
| 3    | 2       | 1      | {1, 0, 0, 3, 12} | nums\[2] is 0 → skip |
| 4    | 3       | 1      | {1, 3, 0, 0, 12} | Swap 3 with 0        |
| 5    | 4       | 2      | {1, 3, 12, 0, 0} | Swap 12 with 0       |

✅ Final Output:

nums = {1, 3, 12, 0, 0};


*/
