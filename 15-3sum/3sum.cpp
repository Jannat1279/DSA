class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;         // Stores the final triplets that sum to zero
        set<vector<int>> uniqueTriplets;    // Used to avoid duplicate triplets

        // If less than 3 elements, no triplet can be formed
        if (nums.size() < 3) return result;

        // Sort the array to make it easier to use two-pointer technique
        sort(nums.begin(), nums.end());

        // Fix the first element of the triplet one by one
        for (int i = 0; i < nums.size() - 2; i++) {

            int left = i + 1;               // Second element pointer
            int right = nums.size() - 1;    // Third element pointer

            // Use two-pointer approach to find pairs that sum with nums[i] to zero
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a triplet → store it in the set to avoid duplicates
                    uniqueTriplets.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    // If sum is less than zero, move left pointer to increase sum
                    left++;
                }
                else {
                    // If sum is greater than zero, move right pointer to decrease sum
                    right--;
                }
            }
        }

        // Transfer unique triplets from set to result vector
        // for (auto it = uniqueTriplets.begin(); it != uniqueTriplets.end(); ++it) {
        //     result.push_back(*it);
        // }

        for(auto& it:uniqueTriplets){
            result.push_back(it);
        }

        return result; // Return all triplets with sum = 0
    }
};
