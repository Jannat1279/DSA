class Solution {
public:
    // Function to count the number of contiguous subarrays where the product of all elements is less than k
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0;          // Two pointers to define the sliding window [i, j]
        int n = nums.size();       // Size of the input array
        int product = 1;           // Product of elements in the current window
        int count = 0;             // Count of valid subarrays
        
        // If k is less than or equal to 1, no product can be less than k
        if (k <= 1) return 0;
        
        // Iterate over the array with pointer j expanding the window
        while (j < n) {
            product *= nums[j];    // Multiply the product by the current element
            
            // Shrink the window from the left (increment i) if product is no longer less than k
            while (product >= k) {
                product /= nums[i]; // Divide by the leftmost element
                i++;                // Shrink the window from the left
            }
            
            // Count the number of subarrays ending at j with product less than k
            // This is the length of the current valid window: (j - i + 1)
            count += (j - i) + 1;
            
            j++;  // Expand the window by moving j forward
        }
        
        // Return the total count of subarrays with product less than k
        return count;
    }
};
