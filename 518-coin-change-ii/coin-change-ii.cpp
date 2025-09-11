class Solution {
public:
    int n; 
    int t[301][5001]; // memoization table: t[i][amount] = number of ways 
                      // to make "amount" using coins from index i..n-1
    
    // Recursive helper function
    int solve(int i, vector<int>& coins, int amount) {
        
        // ✅ Base case 1: If amount becomes 0 → we found one valid combination
        if(amount == 0)
            return t[i][amount] = 1;
        
        // ✅ Base case 2: If we run out of coins OR amount goes negative → no way
        if(i == n || amount < 0)
            return 0;
        
        // ✅ If already computed, return from dp table
        if(t[i][amount] != -1)
            return t[i][amount];
        
        // ✅ Choice 1: Skip current coin if it's larger than amount
        if(coins[i] > amount)
            return t[i][amount] = solve(i+1, coins, amount);
        
        // ✅ Choice 2: Include current coin (stay at same index i, since unlimited coins allowed)
        int take = solve(i, coins, amount - coins[i]);
        
        // ✅ Choice 3: Exclude current coin (move to next index i+1)
        int skip = solve(i+1, coins, amount);
        
        // ✅ Total ways = ways by including + excluding
        return t[i][amount] = take + skip;
    }
    
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(t, -1, sizeof(t)); // initialize memo table with -1
        return solve(0, coins, amount); // start from first coin
    }
};
