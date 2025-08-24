class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1;   // Start from the last character of the string
        int size = 0;               // To store the length of the last word
        
        // Step 1: Skip any trailing spaces at the end of the string
        while (right >= 0 && s.at(right) == ' ') {
            right--;
        }
        
        // Step 2: Count the characters of the last word
        while (right >= 0 && s.at(right) != ' ') {
            right--;
            size++;
        }
        
        // Return the length of the last word
        return size;
    }
};
