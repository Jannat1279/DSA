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

/*
Example:
nums = [1, 2, 3, 1], k=3

Initial State:
i = 0, j = 0
st = {}

Step-by-step:
j = 0:
Window: [ ]
st: {}
nums = 1 not in st
Add 1 to st
st = {1}
j = 1

j = 1:
Window:
st: {1}
nums = 2 not in st
Add 2 to st
st = {1, 2}
j = 2

j = 2:
Window:
st = {1, 2}
nums = 3 not in st
Add 3 to st
st = {1, 2, 3}
j = 3

j = 3:
Window:
st = {1, 2, 3}
nums = 1

Check if 1 is in st → Yes!
⇒ Return true
(Because 1 was seen at index 0, and abs(0 - 3) = 3 <= k)

First revision - 04/08/25
*/
