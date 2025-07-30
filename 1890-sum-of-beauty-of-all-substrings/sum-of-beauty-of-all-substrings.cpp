class Solution {
public:
    // Helper function to get the maximum frequency from the frequency array
    int getMaxCount(vector<int>& freq) {
        int maxCount = 0;
        for (int count : freq) {
            maxCount = max(count, maxCount); // Track maximum frequency
        }
        return maxCount;
    }

    // Helper function to get the minimum non-zero frequency from the frequency array
    int getMinCount(vector<int>& freq) {
        int minCount = INT_MAX;
        for (int count : freq) {
            if (count != 0) {
                minCount = min(count, minCount); // Track minimum non-zero frequency
            }
        }
        return minCount;
    }

    // Function to calculate the beauty sum of all substrings
    int beautySum(string s) {
        int sum = 0;
        int n = s.length();

        // Iterate over all possible substrings
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0); // Frequency array for characters 'a' to 'z'

            // Build substrings starting at index i
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++; // Update frequency of current character

                // Calculate beauty of current substring:
                // difference between max and min non-zero frequencies
                int beauty = getMaxCount(freq) - getMinCount(freq);

                // Add current substring's beauty to total sum
                sum += beauty;
            }
        }

        // Return total beauty sum
        return sum;
    }
};

/*
Example:
// Example to demonstrate beautySum
// Input: s = "aabcb"

/*
Substrings and their character frequencies:

1. "a"      -> freq = {a:1}                -> beauty = 1 - 1 = 0
2. "aa"     -> freq = {a:2}                -> beauty = 2 - 2 = 0
3. "aab"    -> freq = {a:2, b:1}           -> beauty = 2 - 1 = 1
4. "aabc"   -> freq = {a:2, b:1, c:1}      -> beauty = 2 - 1 = 1
5. "aabcb"  -> freq = {a:2, b:2, c:1}      -> beauty = 2 - 1 = 1
6. "a"      -> freq = {a:1}                -> beauty = 1 - 1 = 0
7. "ab"     -> freq = {a:1, b:1}           -> beauty = 1 - 1 = 0
8. "abc"    -> freq = {a:1, b:1, c:1}      -> beauty = 1 - 1 = 0
9. "abcb"   -> freq = {a:1, b:2, c:1}      -> beauty = 2 - 1 = 1
10. "b"     -> freq = {b:1}                -> beauty = 1 - 1 = 0
11. "bc"    -> freq = {b:1, c:1}           -> beauty = 1 - 1 = 0
12. "bcb"   -> freq = {b:2, c:1}           -> beauty = 2 - 1 = 1
13. "c"     -> freq = {c:1}                -> beauty = 1 - 1 = 0
14. "cb"    -> freq = {c:1, b:1}           -> beauty = 1 - 1 = 0
15. "b"     -> freq = {b:1}                -> beauty = 1 - 1 = 0

Total Beauty Sum = 0 + 0 + 1 + 1 + 1 + 0 + 0 + 0 + 1 + 0 + 0 + 1 + 0 + 0 + 0 = 5

So, output = 5
*/

*/
