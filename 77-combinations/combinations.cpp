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

/*
Example:
solve(1,4,2,[])

push 1 → temp = [1]
solve(2,4,1,[1])

push 2 → temp = [1,2]
solve(3,4,0,[1,2]) → k == 0 → add [1,2] to result
return, pop 2 → temp = [1]

solve(3,4,1,[1])
push 3 → temp = [1,3]
solve(4,4,0,[1,3]) → k == 0 → add [1,3]
return, pop 3 → temp = [1]

solve(4,4,1,[1])
push 4 → temp = [1,4]
solve(5,4,0,[1,4]) → k == 0 → add [1,4]
return, pop 4 → temp = [1]

return, pop 1 → temp = []

solve(2,4,2,[])
push 2 → temp = [2]
solve(3,4,1,[2])

push 3 → temp = [2,3]
solve(4,4,0,[2,3]) → add [2,3]
return, pop 3 → temp = [2]

solve(4,4,1,[2])
push 4 → temp = [2,4]
solve(5,4,0,[2,4]) → add [2,4]
return, pop 4 → temp = [2]

return, pop 2 → temp = []

solve(3,4,2,[])
push 3 → temp = [3]
solve(4,4,1,[3])
push 4 → temp = [3,4]
solve(5,4,0,[3,4]) → add [3,4]

return, pop 4 → temp = [3]

solve(4,4,2,[3]) (exclude 3 branch)
push 4 → temp = [4]
solve(5,4,1,[4]) → start > n and k != 0 → no add, return, pop 4

All calls finish.

Final result (in order added)
[[1,2], [1,3], [1,4], [2,3], [2,4], [3,4]]
*/
