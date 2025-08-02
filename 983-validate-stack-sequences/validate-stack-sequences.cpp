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

/*
Example:
pushed = [1,2,3,4,5]

popped = [4,5,3,2,1]

Step-by-step Execution
Start with an empty stack, indexes i = 0 (for pushed), j = 0 (for popped).

Push 1 (pushed)
Stack: 
Check top of stack vs popped[j]: 1 != 4 → No pop
Move i to 1

Push 2 (pushed)
Stack: 
Top = 2, popped[j] = 4 → No pop
Move i to 2

Push 3 (pushed)
Stack: 
Top = 3, popped[j] = 4 → No pop
Move i to 3

Push 4 (pushed)
Stack: 
Top = 4, popped[j] = 4 → Match!
Pop 4 from stack → Stack: 
Increment j to 1 (next popped element is 5)
Check top again: 3 != 5 → stop popping
Move i to 4

Push 5 (pushed)
Stack: 
Top = 5, popped[j] = 5 → Match!
Pop 5 → Stack: 
Increment j to 2 (popped[j] = 3)
Check top: 3 == 3 → Match
Pop 3 → Stack: 
Increment j to 3 (popped[j] = 2)
Check top: 2 == 2 → Match
Pop 2 → Stack: 
Increment j to 4 (popped[j] = 1)
Check top: 1 == 1 → Match
Pop 1 → Stack: []
Increment j to 5 (popped sequence done)

Since stack is empty and all popped elements matched in order, sequences are valid.


*/
