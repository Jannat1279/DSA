class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Hash map to store cumulative prefix sums and their frequencies
        unordered_map<int, int> m;

        int count = 0; // To store the total number of subarrays summing to k
        int sum = 0;   // To maintain the running prefix sum

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i]; // Update the prefix sum

            // Case 1: If the current prefix sum itself is equal to k,
            // we found a valid subarray starting from index 0
            if (sum == k)
                count++;

            // Case 2: If (sum - k) exists in the map,
            // it means there exists a subarray (not necessarily starting at
            // index 0) whose sum is k. We add the frequency of (sum - k) to our
            // count.
            if (m.find(sum - k) != m.end()) {
                count += m[sum - k];
            }

            // Record the current prefix sum in the map
            // If it already exists, increment its frequency
            // Otherwise, insert it with a count of 1
            if (m.find(sum) != m.end()) {
                m[sum]++;
            } else {
                m[sum] = 1;
            }
        }

        // Return the total number of subarrays that sum to k
        return count;
    }
};

/*
Example:
nums = {1, 2, 3}, k = 3

🔹 Explanation:
At index 0:
sum = 1
Not equal to k, and sum - k = -2 not found in map.
So we add 1:1 to the map.

At index 1:
sum = 1 + 2 = 3
Equals k → count = 1
sum - k = 0 not found in map.
Add 3:1 to map.

At index 2:
sum = 3 + 3 = 6
Not equal to k
sum - k = 3 exists in map with frequency 1 → add 1 to count.
Add 6:1 to map.

✅ Final Output:
return count = 2
*/
