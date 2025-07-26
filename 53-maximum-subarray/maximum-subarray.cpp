class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max=nums[0], max_so_far=nums[0];
        for(int i=1;i<nums.size();i++){
            curr_max=max((curr_max+nums[i]),nums[i]);
            max_so_far=max(curr_max, max_so_far);
        }
        return max_so_far;
    }
};