class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        // If the lengths of the two words are not the same, they can't be close
        if (m != n)
            return false;

        // Frequency arrays for each character (a-z)
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Count the frequency of each character in both strings
        for (int i = 0; i < m; i++) {
            char ch1 = word1[i];
            char ch2 = word2[i];

            int ind1 = ch1 - 'a';
            int ind2 = ch2 - 'a';

            freq1[ind1]++;
            freq2[ind2]++;
        }

        // Check that both words contain the **same set of characters**
        for (int i = 0; i < 26; i++) {
            // If a character exists in one word but not the other, return false
            if (freq1[i] != 0 && freq2[i] != 0)
                continue;
            if (freq1[i] == 0 && freq2[i] == 0)
                continue;
            return false;
        }

        // Sort the frequency arrays to compare their structure
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        // Return true only if the sorted frequency distributions match
        return freq1 == freq2;
    }
};
