//Time Complexity: O(m)
//Space Complexity: O(m)

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

/*
Example:
s = "abcde";
goal = "cdeab";
🧠 Logic in rotateString:
// s + s = "abcdeabcde"
// Now check if goal ("cdeab") is a substring of s + s
Let’s break it down:

All possible rotations of "abcde" are:
Rotation	Result
0	        abcde
1	        bcdea
2	        cdeab ✅
3	        deabc
4	        eabcd

So "cdeab" is a valid rotation of "abcde".

Now in the code:
if (s.length() == goal.length() && (s + s).find(goal) != string::npos)
Lengths match ✅
"cdeab" is found in "abcdeabcde" ✅

🔚 Output:
true
*/
