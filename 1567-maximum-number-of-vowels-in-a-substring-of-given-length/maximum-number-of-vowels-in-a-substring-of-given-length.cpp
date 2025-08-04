class Solution {
public:
    // Helper function to check if a character is a vowel (case insensitive)
    bool isVowel(char& c) {
        return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || 
                c == 'i' || c == 'I' || c == 'o' || c == 'O' || 
                c == 'u' || c == 'U');
    }
    
    // Function to find the maximum number of vowels in any substring of length k
    int maxVowels(string s, int k) {
        int count = 0;      // Current count of vowels in the current window
        int maxCount = 0;   // Max number of vowels found in any window so far
        int n = s.length(); // Length of input string

        int i = 0, j = 0;   // Sliding window pointers: i = start, j = end
        
        while (j < n) {
            // If current character s[j] is a vowel, increment count
            if (isVowel(s[j])) {
                count++;
            }
            
            // Once the window size reaches k (fixed size window)
            if (j - i + 1 == k) {
                // Update maxCount if current window vowel count is greater
                maxCount = max(maxCount, count);
                
                // Before sliding the window forward, check if s[i] is a vowel 
                // and decrement count accordingly as s[i] will be removed from the window
                if (isVowel(s[i])) {
                    count--;
                }
                
                // Slide the window forward by moving start pointer
                i++;
            }
            
            // Extend the window by moving end pointer
            j++;
        }
        
        // Return the maximum vowels found in any substring of length k
        return maxCount;
    }
};

/*
Example:
Here’s a step-by-step example using the string s = "azerdii" and window size k = 3:

Step-by-Step Walkthrough
Initial Setup

String: "azerdii"
Window size: k = 3

Start with i = 0, j = 0, count = 0, maxCount = 0
Window [0:2] — "aze"
j=0: 'a' is a vowel → count = 1
j=1: 'z' is not a vowel → count = 1
j=2: 'e' is a vowel → count = 2
Window size (j-i+1) = 3. Update maxCount = max(0, 2) = 2

Slide window: i=0 is 'a' (vowel) → count = 1. Increment i → i=1
Window [1:3] — "zer"
j=3: 'r' is not a vowel → count = 1
Window size (j-i+1) = 3. Update maxCount = max(2, 1) = 2

Slide window: i=1 is 'z' (not a vowel) → count unchanged. Increment i → i=2
Window [2:4] — "erd"

j=4: 'd' is not a vowel → count = 1
Window size = 3. Update maxCount = max(2, 1) = 2

Slide window: i=2 is 'e' (vowel) → count = 0. Increment i → i=3
Window [3:5] — "rdi"

j=5: 'i' is a vowel → count = 1
Window size = 3. Update maxCount = max(2, 1) = 2

Slide window: i=3 is 'r' (not a vowel) → count unchanged. Increment i → i=4
Window [4:6] — "dii"
j=6: 'i' is a vowel → count = 2

Window size = 3. Update maxCount = max(2, 2) = 2
Slide window: i=4 is 'd' (not a vowel) → count unchanged. Increment i → i=5

All substrings of length 3 have been checked.
Final answer: 2 (maximum number of vowels in any substring of length 3).

Output
2
*/
