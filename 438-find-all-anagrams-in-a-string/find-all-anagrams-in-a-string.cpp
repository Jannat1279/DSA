#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();   // length of text
        int n = p.size();   // length of pattern
        vector<int> result;

        if (n > m) return result; // edge case: pattern longer than text

        // Frequency arrays (26 letters)
        vector<int> freq_p(26, 0), freq_s(26, 0);

        // Step 1: Build frequency of pattern
        for (char c : p) {
            freq_p[c - 'a']++;
        }

        // Step 2: Sliding window on s
        int i = 0, j = 0;
        while (j < m) {
            // Add current char to window
            freq_s[s[j] - 'a']++;

            // If window size > n, shrink from left
            if (j - i + 1 > n) {
                freq_s[s[i] - 'a']--;
                i++;
            }

            // If window size == n and frequencies match → anagram found
            if (j - i + 1 == n && freq_s == freq_p) {
                result.push_back(i);
            }

            j++;
        }

        return result;
    }
};
