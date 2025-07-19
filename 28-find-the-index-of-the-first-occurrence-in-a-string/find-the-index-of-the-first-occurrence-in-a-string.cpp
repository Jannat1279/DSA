class Solution {
public:
    // Function to find the first occurrence of 'needle' in 'haystack'
    int strStr(string haystack, string needle) {
        int n = haystack.size(); // Length of haystack string
        int m = needle.size();   // Length of needle string

        // Loop through each possible starting index in haystack
        // Only go up to (n - m) because a match can't start after that
        for (int i = 0; i <= n - m; i++) {
            // Extract substring of length 'm' starting at index 'i' from
            // haystack Compare it directly with needle
            if (haystack.substr(i, m) == needle) {
                return i; // If match found, return starting index
            }
        }

        // If no match is found, return -1
        return -1;
    }
};
