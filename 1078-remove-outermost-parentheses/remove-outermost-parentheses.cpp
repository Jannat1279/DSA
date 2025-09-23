//Time Complexity: O(n)
//Space Complexity: O(n) (for the output string)

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;      // Keeps track of the "balance" of parentheses
        string ans = "";    // Stores the final result (without outer parentheses)

        // Traverse through each character in the string
        for (char ch : s) {
            if (ch == ')') count--;   // A closing bracket decreases balance

            // Only add the character if it's not an "outer" parenthesis
            // i.e., when count is NOT zero
            if (count != 0) ans.push_back(ch);

            if (ch == '(') count++;   // An opening bracket increases balance
        }

        return ans; // Return the processed string
    }
};

/*
Example:
s = "(()())(())"

Step-by-step:

Start with count = 0, ans = ""

Read '(' → increment count = 1 → since count != 0, add '(' → ans = "("
Read '(' → increment count = 2 → add '(' → ans = "(("
Read ')' → decrement count = 1 → add ')' → ans = "(()"
Read '(' → increment count = 2 → add '(' → ans = "(()("
Read ')' → decrement count = 1 → add ')' → ans = "(()()"
Read ')' → decrement count = 0 → don’t add (this was outermost)
Read '(' → increment count = 1 → add '(' → ans = "(()()("
Read '(' → increment count = 2 → add '(' → ans = "(()()(("
Read ')' → decrement count = 1 → add ')' → ans = "(()()(()"
Read ')' → decrement count = 0 → don’t add (outermost again)

Final Answer:
ans = "()()()"
*/
