class Solution {
public:
    int numberOfSubstrings(string s) {
        // mp[0] -> count of 'a', mp[1] -> count of 'b', mp[2] -> count of 'c'
        vector<int> mp(3, 0);

        int n = s.length(); // Length of the string
        int i = 0, j = 0;   // Two pointers for the sliding window
        int res = 0;        // Result to store number of valid substrings

        while (j < n) {
            char ch = s[j];
            mp[ch - 'a']++; // Increment the count for the current character

            // While the current window contains at least one 'a', 'b', and 'c'
            while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0) {
                // All substrings starting from current i to end of string are
                // valid
                res += (n - j);

                // Shrink the window from the left
                mp[s[i] - 'a']--;
                i++;
            }

            // Move the right pointer
            j++;
        }

        return res;
    }
};
