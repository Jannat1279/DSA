class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // Handle cases where k is greater than n by taking modulus
        // e.g., rotating 7 elements by k=10 is same as rotating by k=3
        k %= n;

        // Step 1: Reverse the entire array
        // Example: [1,2,3,4,5,6,7] -> [7,6,5,4,3,2,1]
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements to restore their correct order
        // Example: [7,6,5,4,3,2,1] -> [5,6,7,4,3,2,1]  (for k=3)
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining n-k elements to restore their order
        // Example: [5,6,7,4,3,2,1] -> [5,6,7,1,2,3,4]
        reverse(nums.begin() + k, nums.end());
    }
};
