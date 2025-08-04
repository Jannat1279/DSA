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

/*
Example:
int[] nums = {1, 1, 0, 0, 1, 1, 1, 0};
int k = 2;

| Window (Start - End) | Subarray                  | Zero Count | Action                       | Max Length |
| -------------------- | ------------------------- | ---------- | ---------------------------- | ---------- |
| 0 - 0                |  [1]                      | 0          | valid window                 | 1          |
| 0 - 1                |  [1, 1]                   | 0          | valid window                 | 2          |
| 0 - 2                |  [1, 1, 0]                | 1          | valid window                 | 3          |
| 0 - 3                |  [1, 1, 0, 0]             | 2          | valid window                 | 4          |
| 0 - 4                |  [1, 1, 0, 0, 1]          | 2          | valid window                 | 5          |
| 0 - 5                |  [1, 1, 0, 0, 1, 1]       | 2          | valid window                 | 6          |
| 0 - 6                |  [1, 1, 0, 0, 1, 1, 1]    | 2          | valid window                 | 7          |
| 0 - 7                |  [1, 1, 0, 0, 1, 1, 1, 0] | 3          | too many zeros → slide start |            |
| 1 - 7                |  [1, 0, 0, 1, 1, 1, 0]    | 3          | still too many zeros         |            |
| 2 - 7                |  [0, 0, 1, 1, 1, 0]       | 3          | still too many zeros         |            |
| 3 - 7                |  [0, 1, 1, 1, 0]          | 2          | valid window again           | ✅ still 7  |

First revision - 04/08/25
*/
