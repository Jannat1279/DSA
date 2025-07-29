class Solution {
public:
    bool isVowel(char& ch) {
        return (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' ||
                ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' ||
                ch == 'U');
    }
    bool halvesAreAlike(string s) {
        int n=s.length();
        int mid=n/2;
        int i=0,j=mid;
        int countL=0, countR=0;

        while(i<mid && j<n){
            if(isVowel(s[i]))countL++;
            if(isVowel(s[j]))countR++;

            i++;
            j++;
        }
        return countL==countR;
    }
};