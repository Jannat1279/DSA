class Solution {
public:
    const int M = 1e9 + 7;
    int findPower(long long a, long long b) {
        // Base case
        if (b == 0) {
            return 1;
        }
        // Recursive call
        long long half = findPower(a, b / 2);

        // Square the result and take modulo
        long long result = (half * half) % M;

        // If the exponent is odd, multiply one more 'a' and take modulo
        if (b % 2 == 1) {
            result = (result * a) % M;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        return (long long)findPower(5, (n + 1) / 2) * findPower(4, n / 2)%M;
    }
};

/*
Example:

If n = 4:

Even positions = (4 + 1)/2 = 2 → 
5^2=25

Odd positions = 4 / 2 = 2 → 
4^2=16

Total: 
25×16=400

*/
