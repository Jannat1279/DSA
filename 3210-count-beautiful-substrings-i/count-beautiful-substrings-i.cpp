class Solution {
public:
    // Helper function to check if a character is a vowel (both lowercase and uppercase)
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' ||
                ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U');
    }

    // Function to count the number of "beautiful" substrings
    int beautifulSubstrings(string s, int k) {
        int n = s.length();
        int count = 0; // to store total number of beautiful substrings

        // Iterate over all possible substrings starting from index i
        for (int i = 0; i < n; i++) {
            int countV = 0; // vowel count
            int countC = 0; // consonant count

            // Expand the substring ending at index j
            for (int j = i; j < n; j++) {
                if (isVowel(s[j]))
                    countV++; // increment vowel count if current char is a vowel
                else
                    countC++; // else increment consonant count

                // Check if substring is beautiful
                // A beautiful substring has equal vowels and consonants
                // and (vowel * consonant) divisible by k
                if (countC == countV && (countC * countV) % k == 0) {
                    count++; // increment beautiful substring count
                }
            }
        }

        return count; // return total beautiful substrings
    }
};

/*
Example:
Input:
s = "abac"
k = 2

🔍 Substring Analysis:
Let's examine all possible substrings of "abac":

"a" → vowels = 1, consonants = 0 → ❌ not equal
"ab" → vowels = 1 (a), consonants = 1 (b)
1 * 1 = 1 → not divisible by 2 → ❌

"aba" → vowels = 2 (a, a), consonants = 1 (b) → ❌ not equal
"abac" → vowels = 2 (a, a), consonants = 2 (b, c)
2 * 2 = 4 → divisible by 2 → ✅

"b" → consonant → ❌
"ba" → vowels = 1 (a), consonants = 1 (b)
1 * 1 = 1 → not divisible by 2 → ❌

"bac" → vowels = 1, consonants = 2 → ❌ not equal
"a" → vowel → ❌
"ac" → vowels = 1, consonants = 1
1 * 1 = 1 → not divisible by 2 → ❌

"c" → consonant → ❌

✅ Final Count:
Only one substring ("abac") satisfies:

Equal vowels and consonants
Product divisible by k = 2
Output: 1
*/
