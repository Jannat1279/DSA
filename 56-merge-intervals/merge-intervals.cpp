class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        // If no intervals are given, return empty result
        if (intervals.size() == 0) {
            return res;
        }

        // Sort intervals based on the starting time
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        // Initialize the current interval to be the first interval
        vector<int> curr = intervals[0];

        // Traverse through all the intervals starting from the second one
        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval does not overlap with the next one
            if (curr[1] < intervals[i][0]) {
                res.push_back(curr); // Add the current interval to the result
                curr = intervals[i]; // Move to the next interval
            } else {
                // If there is overlap, merge the intervals by updating the end
                // time
                curr[1] = max(curr[1], intervals[i][1]);
            }
        }

        // Add the last merged interval to the result
        res.push_back(curr);
        return res;
    }
};
