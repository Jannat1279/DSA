class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int oddCount = 0; // Counts number of odd elements in current window
        int count = 0;  // Counts number of valid subarrays ending at current j
        int result = 0; // Total number of nice subarrays

        int i = 0; // Left pointer of the window
        int j = 0; // Right pointer of the window

        // Example: nums = [2, 1, 2, 1], k = 1 => Output: 6
        while (j < n) {

            // If current number is odd, increment oddCount and reset count
            if (nums[j] % 2 != 0) { // Check if nums[j] is ODD
                oddCount++;
                count = 0; // Reset count to avoid overcounting overlapping
                           // subarrays
            }

            // While window has exactly k odd numbers, shrink from left to count
            // valid subarrays
            while (oddCount == k) {
                count++; // Each shrink from the left adds a new valid subarray

                // If nums[i] is odd, we remove one odd from the window
                if (i < n && nums[i] % 2 == 1) {
                    oddCount--;
                }
                i++; // Move left pointer
            }

            // Add the number of valid subarrays found with current j
            result += count;
            j++; // Move right pointer
        }

        return result;
    }
};
