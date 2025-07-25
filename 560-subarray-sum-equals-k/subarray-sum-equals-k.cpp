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
