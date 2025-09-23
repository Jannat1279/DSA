// time - O(n), space - O(1)

class Solution {
public:
    // Function to calculate the maximum depth of nested parentheses in a string
    int maxDepth(string s) {
        int curr = 0; // Tracks the current depth of nested parentheses
        int res = 0;  // Stores the maximum depth encountered so far

        // Traverse each character in the string
        for (char& c : s) {
            // If the character is an opening parenthesis
            if (c == '(') {
                curr++;               // Increase current depth
                res = max(res, curr); // Update max depth if needed
            }
            // If the character is a closing parenthesis
            if (c == ')') {
                curr--; // Decrease current depth as we exit a level
            }
        }

        // Return the maximum depth found
        return res;
    }
};

/*
Example:
string s = "(1+(2*(3+(4/(5+6)))))";

| Character | Action                            | `curr` | `res` |
| --------- | --------------------------------- | ------ | ----- |
| `(`       | opening → `curr++`, `res = max()` | 1      | 1     |
| `1`       | ignore                            | 1      | 1     |
| `+`       | ignore                            | 1      | 1     |
| `(`       | opening → `curr++`, `res = max()` | 2      | 2     |
| `2`       | ignore                            | 2      | 2     |
| `*`       | ignore                            | 2      | 2     |
| `(`       | opening → `curr++`, `res = max()` | 3      | 3     |
| `3`       | ignore                            | 3      | 3     |
| `+`       | ignore                            | 3      | 3     |
| `(`       | opening → `curr++`, `res = max()` | 4      | 4 ✅   |
| `4`       | ignore                            | 4      | 4     |
| `/`       | ignore                            | 4      | 4     |
| `(`       | opening → `curr++`, `res = max()` | 5      | 5 ✅   |
| `5`       | ignore                            | 5      | 5     |
| `+`       | ignore                            | 5      | 5     |
| `6`       | ignore                            | 5      | 5     |
| `)`       | closing → `curr--`                | 4      | 5     |
| `)`       | closing → `curr--`                | 3      | 5     |
| `)`       | closing → `curr--`                | 2      | 5     |
| `)`       | closing → `curr--`                | 1      | 5     |
| `)`       | closing → `curr--`                | 0      | 5     |

*/
