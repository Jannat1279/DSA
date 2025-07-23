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
vector<vector<int>> intervals = {{1, 4}, {2, 5}, {7, 9}};
🧠 Step 1: Sort based on the starting time
Using:
sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
});
This sorts the intervals as:

{{1, 4}, {2, 5}, {7, 9}}
Here it was already sorted, so nothing changes.

🧠 Step 2: Initialize
vector<int> curr = intervals[0];  // curr = {1, 4}
We will compare this with the next intervals to see if they overlap.

🔁 Step 3: Loop through the rest
i = 1 → intervals[i] = {2, 5}
Check if overlapping:
Is curr[1] < intervals[i][0] → Is 4 < 2? → ❌ No overlap

So merge:
curr[1] = max(4, 5) = 5 → curr becomes {1, 5}
i = 2 → intervals[i] = {7, 9}

Check if overlapping:

Is curr[1] < intervals[i][0] → Is 5 < 7? ✅ Yes → No overlap

So:
res.push_back(curr);  // res = {{1, 5}}
curr = {7, 9};

✅ After loop ends:
We push the last curr to result:
res.push_back(curr);  // res = {{1, 5}, {7, 9}}

🧾 Final Output:
{{1, 5}, {7, 9}}
*/
