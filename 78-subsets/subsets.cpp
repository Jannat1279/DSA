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

/*
Example:
nums = [1, 2]

Function Called:
sub(nums, 0, [])

                          sub(0, [])                
                     /                 \
          sub(1, [])                   sub(1, [1])
         /         \                   /        \
  sub(2, [])   sub(2, [2])      sub(2, [1])   sub(2, [1,2])

Level-by-Level Breakdown
1️⃣ sub(0, [])
index = 0, temp = []
No base case yet
Two recursive calls:
Exclude: sub(1, [])
Include: temp.push_back(1) → sub(1, [1])

2️⃣ sub(1, [])
index = 1, temp = []
Again, two calls:
Exclude: sub(2, [])
Include: temp.push_back(2) → sub(2, [2])

3️⃣ sub(2, []) → ✅ Base Case
index = 2 (end of array)
Adds [] to ans
3️⃣ sub(2, [2]) → ✅ Base Case
Adds [2] to ans

2️⃣ sub(1, [1])
index = 1, temp = [1]
Two calls:
Exclude: sub(2, [1])
Include: temp.push_back(2) → sub(2, [1, 2])

3️⃣ sub(2, [1]) → ✅ Base Case
Adds [1] to ans

3️⃣ sub(2, [1, 2]) → ✅ Base Case
Adds [1, 2] to ans
*/
