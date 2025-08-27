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
    vector<vector<int>> ans; // To store all subsets

    // Recursive helper function
    void sub(vector<int>& nums, int i, vector<int> temp) {
        // Base Case: when index reaches end of array
        if (i == nums.size()) {
            ans.push_back(temp); // Add the current subset to the result
            return;
        }

        // Recursive call WITHOUT including nums[i]
        // sub(nums, i + 1, temp); // Explore path excluding current element

        // // Small work: include the current element in the subset
        // temp.push_back(nums[i]);

        // // Recursive call WITH including nums[i]
        // sub(nums, i + 1, temp); // Explore path including current element

        temp.push_back(nums[i]);
        sub(nums,i+1,temp);
        temp.pop_back();
        sub(nums,i+1,temp);
    }

    // Main function
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;   // Temporary subset
        sub(nums, 0, temp); // Start recursion from index 0
        return ans;
    }
};