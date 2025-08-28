class Solution {
public:
    vector<string> v; // stores all valid combinations of parentheses

    // Recursive helper function
    // n  -> total pairs of parentheses required
    // oc -> number of open brackets used so far
    // cc -> number of close brackets used so far
    // s  -> current string being built
    void helper(int n, int oc, int cc, string s) {
        // Base case: if both open and close count reach n, we found a valid combination
        if (oc == n && cc == n) {
            v.push_back(s);
            return;
        }

        // If we still have open brackets left to add, add '('
        if (oc < n) {
            helper(n, oc + 1, cc, s + "(");
        }

        // We can only add a closing bracket if it won’t exceed the number of open ones
        if (cc < oc) {
            helper(n, oc, cc + 1, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        int oc = 0, cc = 0; // initially no open or close brackets used
        helper(n, oc, cc, ""); // start recursion with empty string
        return v; // return all valid combinations
    }
};
