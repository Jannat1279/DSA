class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, vector<int> &candidates, vector<int> &temp, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // \U0001f534 Skip duplicates (only pick the first occurrence at each level)
            if (i > start && candidates[i] == candidates[i-1]) continue;

            // If current number is greater than target, no need to continue
            if (candidates[i] > target) break;

            // Pick candidates[i]
            temp.push_back(candidates[i]);
            solve(i + 1, candidates, temp, target - candidates[i]); // move to next index (no reuse)
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> temp;
        sort(candidates.begin(), candidates.end()); // sort for handling duplicates
        solve(0, candidates, temp, target);
        return ans;
    }
};
