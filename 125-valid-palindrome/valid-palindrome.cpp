class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        // Loop while the two pointers haven't crossed
        while (left < right) {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(s[left])) {
                left++;
            }
            // Skip non-alphanumeric characters from the right
            else if (!isalnum(s[right])) {
                right--;
            }
            // Compare characters (case-insensitive)
            else if (tolower(s[left]) != tolower(s[right])) {
                return false; // Mismatch found, not a palindrome
            } else {
                // Characters matched, move both pointers inward
                left++;
                right--;
            }
        }

        // All characters matched; it's a palindrome
        return true;
    }
};
