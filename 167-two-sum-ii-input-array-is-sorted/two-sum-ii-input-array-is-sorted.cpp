class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();       // Get the size of the input array
        int l = 0, r = n - 1;         // Two pointers: l starts at beginning, r at the end

        while (l < r) {               // Continue until the two pointers meet
            int sum = numbers[l] + numbers[r];  // Calculate current sum

            if (sum == target) 
                // Found the pair → return 1-based indices as required by the problem
                return {l + 1, r + 1}; 
            
            else if (sum < target) 
                // If sum is too small, move left pointer forward to increase sum
                l++; 
            else 
                // If sum is too large, move right pointer backward to decrease sum
                r--; 
        }

        // No solution found (though problem guarantees one solution)
        return {};
    }
};
