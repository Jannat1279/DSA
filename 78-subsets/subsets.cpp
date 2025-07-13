class Solution {
public:
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     int n=nums.size();
    //     int subset=1<<n;
    //     vector<vector<int>>ans;

    //     for(int num=0;num<subset;num++){
    //         vector<int>list;
    //         for(int i=0;i<n;i++){
    //             if(num&1<<i){
    //                 list.push_back(nums[i]);
    //             }
    //         }
    //         ans.push_back(list);
    //     }
    //     return ans;
    // }

    // Recursion:
    vector<vector<int>> ans;
    void sub(vector<int>& nums, int i, vector<int> temp) {
        if (i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        sub(nums, i + 1, temp);
        temp.push_back(nums[i]);
        sub(nums, i + 1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        sub(nums, 0, temp);
        return ans;
    }
};