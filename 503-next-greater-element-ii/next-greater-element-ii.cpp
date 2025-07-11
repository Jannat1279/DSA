class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;                  // Stack to keep track of next greater elements
        int n = nums.size();
        vector<int> nge(n);             // Vector to store the final result

        // We traverse from 2n - 1 down to 0 to simulate circular array behavior
        for (int i = 2 * n - 1; i >= 0; i--) {
            int current = nums[i % n];  // Use modulo to wrap around the array (circular behavior)

            // Remove all elements from the stack that are less than or equal to current
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            // For the first pass (i < n), store the result in nge[]
            if (i < n) {
                // If stack is empty, no greater element exists; else the top is the next greater
                nge[i] = st.empty() ? -1 : st.top();
            }

            // Push current element to stack for future comparisons
            st.push(current);
        }

        return nge;
    }
};
/*
Why 2 * n - 1?
Because the array is circular, each element needs to look ahead possibly into the "next rotation" of the array to find a greater element.

Why i % n?
To simulate wrapping around when index exceeds the length of the array.

Why use a stack?
To efficiently track candidates for the next greater element, ensuring O(n) time complexity.
*/