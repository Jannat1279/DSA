class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0, j = 0;             // Sliding window pointers
        int count = 0;                // Maximum number of fruits we can pick
        unordered_map<int, int> mp;   // To store fruit type -> frequency in window

        // Expand the window with 'j'
        while (j < n) {
            mp[fruits[j]]++;  // Include current fruit in the window

            // If window has at most 2 types of fruits, it's valid
            if (mp.size() <= 2) {
                count = max(count, j - i + 1);  // Update max window size
            } 
            else {
                // Window has more than 2 fruit types → shrink from left
                mp[fruits[i]]--;       // Remove the leftmost fruit
                if (mp[fruits[i]] == 0) 
                    mp.erase(fruits[i]); // Remove type if count becomes zero
                i++;                   // Move left pointer forward
            }

            j++; // Expand window
        }

        return count; // Return the largest valid window size
    }
};
