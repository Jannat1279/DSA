class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> uniqueQuadruplets; // to avoid duplicates
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end()); // sort for two-pointer method

        // Pick first element
        for (int i = 0; i < n - 3; i++) {
            // Pick second element
            for (int j = i + 1; j < n - 2; j++) {
                int k = j + 1, l = n - 1;

                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        uniqueQuadruplets.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } 
                    else if (sum < target) {
                        k++;
                    } 
                    else {
                        l--;
                    }
                }
            }
        }

        // Move unique quadruplets from set to answer
        for (auto &quad : uniqueQuadruplets) {
            ans.push_back(quad);
        }

        return ans;
    }
};
