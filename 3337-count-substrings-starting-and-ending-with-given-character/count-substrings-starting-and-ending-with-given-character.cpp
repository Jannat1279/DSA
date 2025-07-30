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

/*
Example:
s = "abaca"
c = 'a'

| Index | Char | Is `ch == c`? | `count` (after) | `substring += 1 + count` | Total Substrings |
| ----- | ---- | ------------- | --------------- | ------------------------ | ---------------- |
| 0     | 'a'  | ✅ Yes         | 1               | `substring += 1 + 0 = 1` | 1                |
| 1     | 'b'  | ❌ No          | 1               | -                        | 1                |
| 2     | 'a'  | ✅ Yes         | 2               | `substring += 1 + 1 = 2` | 3                |
| 3     | 'c'  | ❌ No          | 2               | -                        | 3                |
| 4     | 'a'  | ✅ Yes         | 3               | `substring += 1 + 2 = 3` | 6                |


*/
