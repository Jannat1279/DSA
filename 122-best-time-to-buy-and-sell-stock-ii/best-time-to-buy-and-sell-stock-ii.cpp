class Solution {
public:
    // Function to compute the maximum profit using recursion + memoization
    // (Top-down DP)
    long getAns(vector<int>& Arr, int ind, int buy, int n, vector<vector<long>>& dp) {
        // Base Case: If we reach the end of the array, no further transactions
        // are possible.
        if (ind == n) {
            return 0;
        }

        // If this subproblem was already solved, return the stored result.
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }

        long profit = 0;

        if (buy == 0) {
            // Case 1: Skip buying today → move to next day, still allowed to
            // buy. Case 2: Buy today → reduce profit by Arr[ind], move to next
            // day, now allowed to sell.
            profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), // Do nothing
                         -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp) // Buy stock
            );
        } else {
            // buy == 1 (we currently hold a stock, so we can sell it)
            // Case 1: Skip selling today → move to next day, still holding the
            // stock. Case 2: Sell today → add Arr[ind] to profit, move to next
            // day, now can buy again.
            profit = max(0 + getAns(Arr, ind + 1, 1, n, dp),       // Do nothing
                         Arr[ind] + getAns(Arr, ind + 1, 0, n, dp) // Sell stock
            );
        }

        // Memoize and return the computed profit for the current state.
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Edge case: No days = no transactions = no profit
        if (n == 0) {
            return 0;
        }

        // Initialize DP table with -1 (not calculated)
        // dp[i][buy] => max profit from day i to end, given buy status
        vector<vector<long>> dp(n, vector<long>(2, -1));

        // Start from day 0, with permission to buy
        long ans = getAns(prices, 0, 0, n, dp);
        return ans;
    }
};