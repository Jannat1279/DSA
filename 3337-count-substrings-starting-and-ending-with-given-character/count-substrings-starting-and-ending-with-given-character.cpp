class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;     // Counts how many times character 'c' appears
        long long substring = 0; // Stores the total number of substrings that
                                 // start and end with 'c'

        for (char& ch : s) {
            // Every time we find character 'c', we can form new substrings
            // with each previous 'c' (including this one)
            if (ch == c) {
                substring += (1 + count); // Add (count + 1) new substrings
                count++;                  // Increment count of 'c'
            }
        }

        return substring;
    }
};
