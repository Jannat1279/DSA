class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (result[0] == -1) result[0] = i; // First time seeing target
                result[1] = i; // Keep updating to get last occurrence
            }
        }

        return result;
    }
};

/*
Example:
nums = [5, 7, 7, 8, 8, 10]
target = 8

output:[3,4]
*/
