class Solution {
public:
    bool isUgly(int n) {
        // An ugly number is a positive number whose prime factors are only 2, 3, and/or 5.
        // Return false if n is less than or equal to 0 (not an ugly number).
        
        while (n > 1) { // Keep dividing until n becomes 1 or an unallowed factor is found
            if (n % 2 == 0) 
                n = n / 2;      // If divisible by 2, divide by 2
            else if (n % 3 == 0) 
                n = n / 3;      // If divisible by 3, divide by 3
            else if (n % 5 == 0) 
                n = n / 5;      // If divisible by 5, divide by 5
            else {
                // If not divisible by 2, 3, or 5, then n has another prime factor → not ugly
                return false;
            }
        }
        
        // If we successfully reduce n to 1, it's an ugly number
        if (n == 1) 
            return true;
        
        return false; // This case is practically unreachable due to the while condition
    }
};
