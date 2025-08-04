class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minL = n + 1; // Initialize minL to a value larger than any possible subarray length
        int sum = 0;      // This will hold the current window sum
        int i = 0, j = 0; // i is the window's start, j is the window's end

        // Move the right end of the window forward
        while (j < n) {
            sum += nums[j]; // Add the current element to the window sum

            // Shrink the window from the left as long as the sum is >= target
            while (sum >= target) {
                minL = min(minL, j - i + 1); // Update the minimum length found
                sum -= nums[i]; // Remove the leftmost element from the window
                i++;            // Move the window start to the right
            }
            j++; // Expand the window to include the next element
        }

        // If no valid subarray was found, return 0; otherwise, return minL
        return (minL == n + 1) ? 0 : minL;
    }
};

/*
Example:
nums = [2, 3, 1, 2, 4, 3]
target=7

| Step | i   | j   | nums[j] | sum       | Action                                                     | minL |
|-------|-----|-----|---------|-----------|------------------------------------------------------------|------|
| 1     | 0   | 0   | 2       | 2         | sum < 7, expand window                                      |      |
| 2     | 0   | 1   | 3       | 5         | sum < 7, expand window                                      |      |
| 3     | 0   | 2   | 1       | 6         | sum < 7, expand window                                      |      |
| 4     | 0   | 3   | 2       | 8 (2+3+1+2)| sum ≥ 7, try to shrink window                                |      |
|       | 0→1 | 3   |         | 6 (8 - 2) | minL = 4 (j - i + 1), move i right, subtract nums[i]       | 4    |
| 5     | 1   | 4   | 4       | 10 (6+4)  | sum ≥ 7, shrink window                                      |      |
|       | 1→2 | 4   |         | 7 (10 -3) | minL = 4 (no change), move i right                          | 4    |
|       | 2→3 | 4   |         | 6 (7 - 1) | minL = 3 (j - i + 1), move i right                          | 3    |
| 6     | 3   | 5   | 3       | 9 (6+3)   | sum ≥ 7, shrink window                                      |      |
|       | 3→4 | 5   |         | 7 (9 - 2) | minL = 3 (no change), move i right                          | 3    |
|       | 4→5 | 5   |         | 3 (7 - 4) | minL = 2 (j - i + 1), move i right                          | 2    |


After the loop, the shortest subarray length found is 2, corresponding to the subarray [4,Summary:
The shortest length of a contiguous subarray whose sum ≥ 7 is 2, and one valid subarray is [4,You can trace the logic step by step for any input using this table-style breakdown!
*/
