class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(); // Size of the pushed sequence
        int i = 0, j = 0;      // i -> index for pushed, j -> index for popped
        stack<int> st;         // stack to simulate push/pop operations

        // Iterate over all elements in pushed array
        while (i < n && j < n) {
            st.push(pushed[i]); // Push the next element from pushed sequence
                                // onto the stack
            // Check if the top of the stack matches the next element to pop
            while (!st.empty() && j < n && st.top() == popped[j]) {
                st.pop(); // Pop if it matches the popped sequence
                j++;      // Move to the next element in popped sequence
            }
            i++; // Move to the next element in pushed sequence
        }

        // If stack is empty, all popped elements matched correctly
        // Otherwise, the given pushed and popped sequences are not valid stack
        // operations
        return st.empty();
    }
};
