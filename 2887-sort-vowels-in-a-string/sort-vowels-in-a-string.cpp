class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' ||
                ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U');
    }
    string sortVowels(string s) {
        string temp;
        for (char& ch : s) {
            if (isVowel(ch)) {
                temp.push_back(ch);
            }
        }
        // temp contains all the vowels sorted on the basis of their ASCII
        // values.
        sort(temp.begin(), temp.end());
        int j = 0;
        for (int i = 0; i < s.length(); i++) {

            if (isVowel(s[i])) {
                // Putting the vowels in the sorted order in the original string
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};