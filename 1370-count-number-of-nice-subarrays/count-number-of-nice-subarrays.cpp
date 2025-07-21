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

/*
Example:
Input: nums = [2, 1, 2, 1], k = 1
Expected Output: 6
We need to count the number of subarrays with exactly 1 odd number.

🔁 Let's walk through it:
Initial state:
oddCount = 0
count = 0
result = 0
i = 0, j = 0

Step-by-step:
✅ j = 0 → nums[0] = 2 (even)
Not odd → oddCount unchanged
oddCount != k, so inner while is skipped
result += count → 0
j++
➡️ result: 0, count: 0, oddCount: 0

✅ j = 1 → nums[1] = 1 (odd)
oddCount = 1
Reset count = 0
Now oddCount == k, enter inner while:
count++ → count = 1
nums[i] = 2 (even), so i++
nums[i] = 1 (odd), decrement oddCount = 0, i++
Exit while
result += count → result = 1
j++
➡️ result: 1, count: 1, oddCount: 0, i: 2

✅ j = 2 → nums[2] = 2 (even)
Not odd
oddCount != k, skip inner while
result += count → result = 1 + 1 = 2
j++
➡️ result: 2, count: 1, oddCount: 0

✅ j = 3 → nums[3] = 1 (odd)
oddCount = 1, reset count = 0
Now oddCount == k, enter inner while:
count++ → count = 1
nums[i] = 2 (even), i++
nums[i] = 1 (odd), oddCount = 0, i++
Exit while
result += count → result = 2 + 1 = 3
j++
➡️ result: 3, count: 1, i: 4

Now j = 4 → loop ends
But remember, each time the while (oddCount == k) loop runs, it counts multiple subarrays starting from i...j that are valid.
🎯 Final result = 6

Let’s list them all:
[1]
[2, 1]
[1, 2]
[2, 1, 2]
[1]
[2, 1]

✅ Final Answer:
Output: 6
*/
