class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n > 0) {
            // If remainder is 2, it means we would need to use 2 * (power of 3)
            // which is not allowed since we can only use each power of 3 at most once
            if(n % 3 == 2) {
                return false;
            }

            // Move to the next higher power of 3 (divide by 3)
            n = n / 3;
        }

        // If we never encountered a remainder of 2, return true
        return true;
    }    
    
};