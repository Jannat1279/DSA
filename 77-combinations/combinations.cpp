class Solution {
public:
    vector<vector<int>> result; // Stores all possible combinations

    // Recursive function to generate combinations
    void solve(int start, int n, int k, vector<int>& temp) {
        // Base case: if k == 0, we have selected 'k' elements successfully
        if (k == 0) {
            result.push_back(temp); // Add the current combination to the result
            return;
        }

        // If the starting number exceeds n, no more numbers are left to pick
        if (start > n) return;

        // Choice 1: Include the current number 'start' in the combination
        temp.push_back(start);
        solve(start + 1, n, k - 1, temp); // Move to the next number with one less element to pick

        // Backtrack: remove the last added number and try without including 'start'
        temp.pop_back();
        solve(start + 1, n, k, temp); // Move to the next number but keep k unchanged
    }

    // Main function to get all combinations of size k from numbers 1 to n
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp; // Temporary vector to store current combination
        solve(1, n, k, temp); // Start recursion from number 1
        return result; // Return all collected combinations
    }
};
