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

/*
Example:
string s = "()))((";
Step-by-step Execution:
We initialize:

stack<char> st = {}
int open = 0

Now, we iterate over each character:

1. ch = '('
It’s an opening bracket, so we push it.
stack = ['(']
open = 0

2. ch = ')'
It's a closing bracket, and the stack is not empty (contains '('), so we pop.
stack = []
open = 0

3. ch = ')'
Stack is empty → unmatched closing bracket
open++ → open = 1

4. ch = ')'
Stack still empty → unmatched closing bracket
open++ → open = 2

5. ch = '('
Opening bracket → push to stack
stack = ['(']
open = 2

6. ch = '('
Opening bracket → push to stack
stack = ['(', '(']
open = 2

Final State:
stack.size() = 2 (two unmatched '(')

open = 2 (two unmatched ')')

Return:
return open + st.size();  // 2 + 2 = 4
*/
