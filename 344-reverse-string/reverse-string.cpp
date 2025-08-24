class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();   // Get the size of the string (vector of characters)
        int st = 0;         // Start pointer (points to the beginning of the string)
        int e = n - 1;      // End pointer (points to the last character of the string)
        
        // Keep swapping characters until start crosses end
        while (st < e) {
            swap(s[st++], s[e--]);  
            // swap characters at st and e, 
            // then increment st and decrement e
        }
    }
};

