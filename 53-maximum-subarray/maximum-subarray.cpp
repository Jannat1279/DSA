class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far=nums[0];
        int curr_max=nums[0];
        for(int j=1;j<nums.size();j++){
            curr_max=max(nums[j],nums[j]+curr_max);
            max_so_far=max(curr_max,max_so_far);
        }
        return max_so_far;
    }
};