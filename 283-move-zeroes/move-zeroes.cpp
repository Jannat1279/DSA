class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0, right=0;
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