// time - O(n), space - O(1)

class Solution {
public:

    // Function to calculate the number of distinct ways to climb 'n' stairs,
    // where you can either take 1 or 2 steps at a time.
    int climbStairs(int n) {
        // Base cases:
        // If there are 0 or 1 stairs, there's only one way to climb them.
        if(n == 0 || n == 1) return 1;

        // Create a DP (Dynamic Programming) array to store the number of ways to reach each step.
        vector<int> dp(n + 1);

        // Initialization: There is 1 way to stay at step 0 (do nothing),
        // and 1 way to reach step 1 (take one 1-step).
        dp[0] = 1;
        dp[1] = 1;

        // Fill the dp array using the recurrence relation:
        // dp[i] = dp[i-1] + dp[i-2]
        // Which means: To reach step i, you can come from (i-1) with a 1-step,
        // or from (i-2) with a 2-step.
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // The answer is the number of ways to reach the nth step.
        return dp[n];
    }
};
