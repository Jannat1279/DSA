class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0, actualSum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        actualSum=n*(n+1)/2;
        return actualSum-sum;
    }
};