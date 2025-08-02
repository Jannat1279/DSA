class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st; // Create a stack to help remove adjacent duplicates
        string result =
            ""; // Result string to store the output in correct order

        // Traverse the input string from the end to the beginning
        for (int i = s.length() - 1; i >= 0; i--) {
            // If the current character is the same as the character at the top
            // of the stack, pop the top element (remove the duplicate)
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
            } else {
                // Otherwise, push current character onto the stack
                st.push(s[i]);
            }
        }

        // Build the result string by popping all elements from the stack (in
        // correct order)
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result; // Return the final string without adjacent duplicates
    }
};
