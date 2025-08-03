class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_set<int> st; // Tracks elements in the current sliding window
                               // of size at most k

        int i = 0, j = 0; // Window: elements between i and j-1 (both inclusive)

        while (j < n) {

            // If window size exceeds k, remove the leftmost element
            // abs(i-j) > k means window size > k (because i always <= j)
            if (abs(i - j) > k) {
                st.erase(nums[i]); // Remove leftmost
                i++;               // Move window forward
            }

            // Check if nums[j] is already in the window (duplicate within k
            // distance)
            if (st.find(nums[j]) != st.end()) {
                return true; // Found duplicate within range
            }

            st.insert(nums[j]); // Add current element to window
            j++;                // Expand window to the right
        }

        return false; // No such pair found
    }
};
