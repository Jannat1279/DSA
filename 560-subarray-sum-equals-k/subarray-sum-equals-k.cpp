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
nums = [1, 2, 3, -2, 1], k = 3
We want to count the number of subarrays (contiguous segments) whose sum is 3.

✅ Prefix Sum + HashMap Approach (Your Code):
We use:
sum: the current prefix sum
map[sum]: number of times a prefix sum has occurred

Step-by-step:

i = 0 → sum = 1
→ map: {1: 1}

i = 1 → sum = 3
→ sum == k → count = 1
→ map: {1: 1, 3: 1}

i = 2 → sum = 6
→ sum - k = 3 → map[3] exists → count += 1 (subarray: [3])
→ count = 2
→ map: {1: 1, 3: 1, 6: 1}

i = 3 → sum = 4
→ sum - k = 1 → map[1] exists → count += 1 (subarray: [2, 3, -2])
→ count = 3
→ map: {1: 1, 3: 1, 6: 1, 4: 1}

i = 4 → sum = 5
→ sum - k = 2 → map[2] doesn't exist → count stays 3
→ map: {1: 1, 3: 1, 6: 1, 4: 1, 5: 1}

✅ Final Count = 3
Valid subarrays:
[1, 2]
[3]
[2, 3, -2]
*/
