class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>
            ngeMap; // Stores the next greater element for each number in nums2
        stack<int> st; // Monotonic stack to find the next greater element

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int current = nums2[i];

            // Pop elements from the stack that are less than or equal to
            // current
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            // If stack is empty, no greater element to the right
            if (st.empty()) {
                ngeMap[current] = -1;
            } else {
                ngeMap[current] =
                    st.top(); // Top of the stack is the next greater
            }

            st.push(current); // Push current element to stack
        }

        // Replace elements in nums1 with their next greater from the map
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = ngeMap[nums1[i]];
        }

        return nums1;
    }
    };