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

/*
Example:

Step 1: Input
intervals = [[1,3], [2,6], [8,10], [15,18]]

Step 2: Sort intervals by start
After sort → [[1,3], [2,6], [8,10], [15,18]]
(Already sorted, so nothing changes.)

Step 3: Initialize
curr = [1,3]
res = []

Step 4: Traverse
i = 1 → interval = [2,6]
curr = [1,3], new = [2,6]
Overlap check: 3 ≥ 2 ✅ (they overlap)
Merge → curr = [1, max(3,6)] = [1,6]
curr = [1,6]
res = []

i = 2 → interval = [8,10]
curr = [1,6], new = [8,10]
Overlap check: 6 < 8 ❌ (no overlap)
Push curr → res = [[1,6]]
Update curr = [8,10]
curr = [8,10]
res = [[1,6]]


i = 3 → interval = [15,18]
curr = [8,10], new = [15,18]
Overlap check: 10 < 15 ❌ (no overlap)
Push curr → res = [[1,6],[8,10]]
Update curr = [15,18]
curr = [15,18]
res = [[1,6],[8,10]]

Step 5: Push last interval
res = [[1,6],[8,10],[15,18]]

✅ Final Output:

[[1,6],[8,10],[15,18]]
*/
