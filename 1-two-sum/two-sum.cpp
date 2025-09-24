class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i]+nums[j]==target){
    //                 return {i,j};
    //             }
    //         }
    //     }
    //     return {};
    // }
//time - O(n^2), space - O(1)

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end())
                return {m[complement], i};

            m[nums[i]] = i;
        }
        return {};
    }
};
