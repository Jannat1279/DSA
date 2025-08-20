class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long result = 0;   // To store the total count of valid subarrays
        long long sum = 0;      // To keep track of the current window sum
        int i = 0, j = 0;       // Two pointers for sliding window

        // Expand the window with 'j'
        while (j < n) {
            sum += nums[j];  // Add current element to window sum

            // Shrink the window from the left until the condition is satisfied
            // Condition: sum * (window size) < k
            while (i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];  // Remove the leftmost element
                i++;             // Shrink the window
            }

            // All subarrays ending at 'j' and starting from [i..j] are valid
            result += (j - i + 1);

            j++; // Expand window
        }

        return result; // Return total count of valid subarrays
    }
};
