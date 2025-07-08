class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sum will store the summation of the elements present in the array
        // i.e. nums
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }
        // This is the actual sum claculated using math formula.
        int actualSum = (n * (n + 1)) / 2;
        int missingNumber = actualSum - sum;
        return missingNumber;
    }
};
