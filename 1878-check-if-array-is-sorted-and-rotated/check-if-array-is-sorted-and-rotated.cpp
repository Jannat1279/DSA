class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0, m=nums.size();
        for(int i=0;i<m;i++){
            // allows us to compare the last element to the first, so we can catch the rotation point.
            if(nums[i]>nums[(i+1)%m]){
                count++;
            }
        }
        return (count<=1);
    }
};