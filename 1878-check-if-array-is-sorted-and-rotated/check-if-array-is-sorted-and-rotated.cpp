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

/*
nums[]=[2, 1, 3, 4]

nums[0] > nums[1] → 2 > 1 ✅
nums[1] > nums[2] → 1 > 3 ❌
nums[2] > nums[3] → 3 > 4 ❌
nums[3] > nums[0] → 4 > 2 ✅

count=2, not rotated and sorted.
*/
