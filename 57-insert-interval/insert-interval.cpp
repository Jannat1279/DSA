class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> result;
        
        // Step 1: Add all intervals that come BEFORE the newInterval
        while(i < intervals.size()) {
            if(intervals[i][1] < newInterval[0]) {
                // current interval ends before newInterval starts → no overlap
                result.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                // current interval starts after newInterval ends → stop, we'll handle later
                break;
            } else {
                // Step 2: Overlap case → merge intervals
                // expand newInterval to cover the overlapping range
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        
        // Step 3: Insert the merged interval
        result.push_back(newInterval);
        
        // Step 4: Add all remaining intervals (after merging is done)
        while(i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};
