class Solution {
public:
    string removeStars(string s) {
        stack<char> st;         // Stack to keep track of the characters
        int n = s.length();     // Length of input string
        string result = "";     // String to store the final answer

        // Traverse the string from start to end
        for(int i = 0; i < n; i++) {
            if (!st.empty() && s[i] == '*') {
                // If the current character is '*', remove (pop) the top element of the stack
                // This simulates removing the previous character as per the problem's rule
                st.pop();
            } else {
                // If it's not '*', push the character onto the stack
                st.push(s[i]);
            }
        }

        // After processing, the stack contains the resulting characters (in reverse order)
        while(!st.empty()) {
            result += st.top();  // Add top element to result string
            st.pop();            // Remove top element from stack
        }

        // Since we built result from the stack (which is LIFO), the characters are in reverse order
        // So, reverse the result string before returning
        reverse(result.begin(), result.end());

        return result;           // Return the final string after all '*' removals
    }
};

/*
Example:
string s = "ab*c*d";
Goal:
Every time you encounter a '*', remove the closest previous non-'*' character.
After removing all stars and their corresponding characters, return the resulting string.

Step-by-Step Trace
Input string: "a b * c * d"

Index and char:
0:'a', 1:'b', 2:'', 3:'c', 4:'', 5:'d'

Iteration Details:
i = 0 ('a'): Stack is empty, push 'a'
Stack: a

i = 1 ('b'): Stack not empty, current char is 'b' (not '*'), push 'b'
Stack: a b

i = 2 ('*'): Current char is '*' and stack is not empty, pop top ('b')
Stack: a

i = 3 ('c'): Push 'c'
Stack: a c

i = 4 ('*'): Current char is '*', pop top ('c')
Stack: a

i = 5 ('d'): Push 'd'
Stack: a d

Stack After Loop
Stack contents (bottom to top): a d

Build Result String
Pop from stack and add to result:

Pop 'd' → result = "d"
Pop 'a' → result = "da"
Since the result string is built in reverse order, reverse it:
"da" reversed is "ad"

Final Output
"ad"
*/
