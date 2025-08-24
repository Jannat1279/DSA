class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);   // LPS (Longest Prefix Suffix) array
        
        int len = 0;  // length of the current longest prefix that is also a suffix
        int i = 1;    // start from the 2nd character (first char lps is always 0)

        // Build the LPS array using KMP preprocessing logic
        while (i < n) {
            if (s[i] == s[len]) {
                // If current char matches the char at current prefix length
                len++;             // extend prefix-suffix match
                lps[i] = len;      // store match length at index i
                i++;               // move to next character
            } else {
                if (len != 0) {
                    // If mismatch but we have some matched prefix,
                    // fall back to the previous possible prefix length
                    len = lps[len - 1];
                } else {  
                    // If mismatch and no prefix matched, set lps[i] = 0
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // The last value in LPS array = length of longest prefix also a suffix
        int longest = lps[n - 1];

        // Return that prefix substring
        return s.substr(0, longest);
    }
};

/*
Example:
s = "ababab"

Step 1: Initialize
n = 6
lps = [0,0,0,0,0,0]
len = 0 (length of current longest prefix-suffix)
i = 1

Step 2: Build LPS array
Compare s[i] with s[len]

i=1 → s[1] = b, s[0] = a → mismatch → lps[1] = 0, i=2
lps = [0,0,0,0,0,0]

i=2 → s[2] = a, s[0] = a → match → len=1, lps[2] = 1, i=3
lps = [0,0,1,0,0,0]

i=3 → s[3] = b, s[1] = b → match → len=2, lps[3] = 2, i=4
lps = [0,0,1,2,0,0]

i=4 → s[4] = a, s[2] = a → match → len=3, lps[4] = 3, i=5
lps = [0,0,1,2,3,0]

i=5 → s[5] = b, s[3] = b → match → len=4, lps[5] = 4, i=6
lps = [0,0,1,2,3,4]

Step 3: Final Answer
lps[n-1] = lps[5] = 4
Longest happy prefix length = 4
s.substr(0,4) = "abab"

✅ Output = "abab"
*/
