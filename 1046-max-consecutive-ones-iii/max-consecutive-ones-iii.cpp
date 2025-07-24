class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0; // Number of 0s in the current window
        int start = 0;     // Start index of the sliding window
        int max_ones = 0;  // Result to store the maximum window length

        // Iterate through the array with 'end' as the right boundary of the
        // window
        for (int end = 0; end < nums.size(); end++) {

            // If the current number is 0, increase zeroCount
            if (nums[end] == 0)
                zeroCount++;

            // If zeroCount exceeds k, shrink the window from the left
            while (zeroCount > k) {
                // If the number being removed from the window is 0, reduce
                // zeroCount
                if (nums[start] == 0)
                    zeroCount--;

                // Move the start of the window forward
                start++;
            }

            // Update the maximum window size if the current window is larger
            max_ones = max(max_ones, end - start + 1);
        }

        return max_ones;
    }
};