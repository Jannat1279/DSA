class Solution {
public:
    // Function to compute the minimum number of parentheses needed
    // to make the given string of parentheses valid
    int minAddToMakeValid(string s) {
        stack<char> st; // Stack to track unmatched opening brackets '('
        int open = 0;   // Counter for unmatched closing brackets ')'

        // Traverse each character in the string
        for (char& ch : s) {
            if (ch == '(') {
                // If it's an opening bracket, push to stack
                st.push(ch);
            } else if (!st.empty()) {
                // If it's a closing bracket and stack is not empty,
                // it matches with an opening one, so pop the stack
                st.pop();
            } else {
                // If it's a closing bracket but no matching opening,
                // increment the unmatched closing counter
                open++;
            }
        }

        // Total unmatched = unmatched closing (open) + unmatched opening (stack
        // size)
        return open + st.size();
    }
};