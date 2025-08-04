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
