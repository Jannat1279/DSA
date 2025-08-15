class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0; // Variable to store the result
        
        // Loop through all elements in the array
        for (int num : nums) {
            // XOR operation:
            // - If two numbers are the same, XOR will make them 0 (num ^ num = 0)
            // - 0 ^ num = num
            // - Since all elements except one appear twice, pairs will cancel out
            // - The remaining single element will be stored in 'res'
            res = res ^ num;
        }
        
        return res; // Return the element that appears only once
    }
};
