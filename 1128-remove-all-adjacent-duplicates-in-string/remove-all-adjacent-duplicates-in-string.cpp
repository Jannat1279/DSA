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

/*
Example:
string s = "abbaca";
Step-by-Step Trace
The function processes the string from right to left ("a", "c", "a", "b", "b", "a").

It uses a stack to keep track of characters, removing adjacent duplicates.

Iteration Details:
i = 5 ("a"): Stack is empty, push 'a'
Stack: a

i = 4 ("c"): Top of stack is 'a' (not equal to 'c'), push 'c'
Stack: a c

i = 3 ("a"): Top is 'c' (not equal), push 'a'
Stack: a c a

i = 2 ("b"): Top is 'a' (not equal), push 'b'
Stack: a c a b

i = 1 ("b"): Top is 'b' (equal), pop
Stack: a c a

i = 0 ("a"): Top is 'a' (equal), pop
Stack: a c

Stack After Loop:
Stack contains: a c (bottom to top)

Building Result:
Pop the stack and append to result:
Pop 'c', result = "c"
Pop 'a', result = "ca"

Final Output:
return "ca";
*/
