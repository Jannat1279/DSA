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

/*
Example:
nums = [10, 5, 2, 6]
k=100

Step-by-Step Walkthrough
Initialize variables:

i = 0, j = 0
product = 1
count = 0

j = 0 (Element = 10):
Multiply product by nums → product = 1 * 10 = 10
product < k (10 < 100), so no need to shrink window
Number of subarrays ending at j = (j - i + 1) = (0 - 0 + 1) = 1
count = 0 + 1 = 1

Current window:
j = 1 (Element = 5):
Multiply product by nums → product = 10 * 5 = 50
product < k (50 < 100), no shrink needed
Number of subarrays ending at j = (1 - 0 + 1) = 2
count = 1 + 2 = 3

Current window: [10, j = 2 (Element = 2):
Multiply product by nums → product = 50 * 2 = 100
product >= k (100 >= 100), shrink window:
Divide product by nums[i] → product = 100 / 10 = 10
Increment i → i = 1
product < k (10 < 100), stop shrinking
Number of subarrays ending at j = (2 - 1 + 1) = 2
count = 3 + 2 = 5

Current window: [5,. j = 3 (Element = 6):
Multiply product by nums → product = 10 * 6 = 60
product < k (60 < 100), no shrink needed
Number of subarrays ending at j = (3 - 1 + 1) = 3
count = 5 + 3 = 8

Current window: [5,## Final Result:

The total number of contiguous subarrays where the product is less than 100 is 8.
*/
