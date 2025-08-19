class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(nums[i]*nums[i]);
        }
        sort(res.begin(),res.end());
        return res;
    }
};

/*
Example:
Input:
nums = [-4, -1, 0, 3, 10]

Step 1 – Square each number:

(-4)² = 16
(-1)² = 1
(0)² = 0
(3)² = 9
(10)² = 100

res = [16, 1, 0, 9, 100]

Step 2 – Sort the array:
res = [0, 1, 9, 16, 100]

✅ Output: [0, 1, 9, 16, 100]
*/
