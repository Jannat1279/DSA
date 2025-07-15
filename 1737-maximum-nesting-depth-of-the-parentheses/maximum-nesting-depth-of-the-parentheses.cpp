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
