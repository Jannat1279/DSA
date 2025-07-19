class Solution {
public:
    // Function to check if 'goal' is a rotation of string 's'
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        // A rotation is only possible if both strings are of the same length
        // (s + s) contains all possible rotations of s as substrings
        // So, check if goal is a substring of (s + s)
        if (m == n && (s + s).find(goal) != string::npos)
            return true;  // goal is a valid rotation of s

        return false;  // otherwise, not a rotation
    }
};
