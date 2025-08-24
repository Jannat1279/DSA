class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);   // LPS array
        
        int len = 0;  // length of the current longest prefix-suffix
        int i = 1;    // start from the 2nd character

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // fallback
                } else {
                    
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int longest = lps[n - 1];  // length of longest prefix-suffix
        return s.substr(0, longest);
    }
};
