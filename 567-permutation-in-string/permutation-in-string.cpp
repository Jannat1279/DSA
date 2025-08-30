class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();   // Length of s1 (pattern we want to check as permutation)
        int m = s2.size();   // Length of s2 (text in which we search)
        
        // If s1 is longer than s2, it can't be a substring
        if (n > m) return false;

        // Frequency arrays for s1 and current window of s2
        vector<int> freq_s1(26, 0);
        vector<int> freq_s2(26, 0);

        // Step 1: Count frequency of characters in s1
        for (int i = 0; i < n; i++) {
            freq_s1[s1[i] - 'a']++;
        }

        // Two pointers for sliding window over s2
        int i = 0, j = 0;

        // Step 2: Traverse s2 with sliding window
        while (j < m) {
            // Add current character in s2 to window frequency
            freq_s2[s2[j] - 'a']++;

            // If window size exceeds size of s1, shrink from left
            if (j - i + 1 > n) {
                freq_s2[s2[i] - 'a']--;  // remove leftmost char
                i++;                     // move window forward
            }

            // If frequency matches, it means a permutation of s1 exists in s2
            if (freq_s1 == freq_s2) return true;

            // Expand window
            j++;
        }

        // No permutation of s1 found in s2
        return false;
    }
};
