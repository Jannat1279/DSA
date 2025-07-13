class Solution {
public:
    // Recursive helper function to compute x^n
    double solve(double x, long n) {
        // Base case: any number raised to power 0 is 1
        if (n == 0)
            return 1;

        // If power is negative, invert the base and make exponent positive
        if (n < 0)
            return solve(1 / x, -n);

        // If exponent is even: x^n = (x^2)^(n/2)
        if (n % 2 == 0)
            return solve(x * x, n / 2);

        // If exponent is odd: x^n = x * (x^2)^((n-1)/2)
        return x * solve(x * x, (n - 1) / 2);
    }

    // Main function that casts int n to long (to handle INT_MIN edge case)
    double myPow(double x, int n) { return solve(x, (long)n); }
};

/*
Example:
solve(2.0, 5)
→ 2 * solve(4.0, 2)
→ 2 * solve(16.0, 1)
→ 2 * 16 * solve(256.0, 0)
→ 2 * 16 * 1 = 32

*/
