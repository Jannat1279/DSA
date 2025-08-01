class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        // You can also try from l = n/2 to l = 1 -> for(int l = n/2; l >= 0;
        // l--) //This can be helpful for large test valid cases to return early
        for (int l = 1; l <= n / 2; l++) {

            if (n % l == 0) {
                int times = n / l;

                string pattern = s.substr(0, l);
                string newStr = "";
                while (times--) {
                    newStr += pattern;
                }

                if (newStr == s)
                    return true;
            }
        }

        return false;
    }
};
