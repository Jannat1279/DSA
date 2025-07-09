#include<bits/stdc++.h>
class Solution {
public:
  bool isValid(string s) {
    stack<char> st; // Stack to store opening brackets

    for (char c : s) {
        // If the current character is an opening bracket, push to stack
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            // If it's a closing bracket and stack is empty, it's invalid
            if (st.empty()) return false;

            char top = st.top();
            // Check for matching bracket types
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                st.pop(); // Match found, remove the opening bracket
            } else {
                return false; // Mismatch
            }
        }
    }

    // If stack is empty, all brackets matched; otherwise, some are unclosed
    return st.empty();
}
};

/*
Example:
Input:
s = "{[()]}"

stack: []                   // Start with an empty stack

Read '{'  → push            → stack = ['{']
Read '['  → push            → stack = ['{', '[']
Read '('  → push            → stack = ['{', '[', '(']
Read ')'  → matches '('     → pop     → stack = ['{', '[']
Read ']'  → matches '['     → pop     → stack = ['{']
Read '}'  → matches '{'     → pop     → stack = []

Final stack: []             // Empty → all brackets matched

Output : true
*/
