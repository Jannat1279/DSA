//Time Complexity: O(n)
//Space Complexity: O(1)

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

/*
Example:
s = "A man, a plan, a canal: Panama"

🔁 Step-by-Step Execution:
Initialize two pointers:
left = 0  (points to 'A')
right = 29 (points to 'a')

Compare characters:
A vs a → both are alphanumeric → lowercase: 'a' == 'a' ✅
Move inward: left = 1, right = 28

left = 1 → ' ' (space) → skip → left = 2
s[2] = 'm', s[28] = 'm' → match ✅ → left = 3, right = 27
s[3] = 'a', s[27] = 'a' → match ✅ → left = 4, right = 26
s[4] = 'n', s[26] = 'n' → match ✅ → left = 5, right = 25
s[5] = ',' → skip → left = 6
s[6] = ' ' → skip → left = 7
s[7] = 'a', s[25] = 'a' → match ✅ → left = 8, right = 24
s[8] = ' ' → skip → left = 9
s[9] = 'p', s[24] = 'p' → match ✅ → left = 10, right = 23
... and so on, continuing the same way.
Eventually, all matched alphanumeric characters from both ends match when compared case-insensitively.

✅ Final Result:
All characters matched → it is a palindrome.

Return: true


*/
