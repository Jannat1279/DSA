//Time Complexity: O(n)
//Space Complexity: O(1)

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

/*
Example:

s = ['h','e','l','l','o']

n = 5, st = 0, e = 4
Swap s[0] and s[4] → ['o','e','l','l','h']

Now st = 1, e = 3.
st = 1, e = 3
Swap s[1] and s[3] → ['o','l','l','e','h']

Now st = 2, e = 2.
st = 2, e = 2 → loop stops because st is not < e.

Final Output:
s = ['o','l','l','e','h']
*/
