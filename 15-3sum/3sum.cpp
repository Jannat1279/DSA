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

/*
Example:
nums = {-1, 0, 1, 2, -1, -4}

Step 1: Sort the array
After sorting:
nums = [-4, -1, -1, 0, 1, 2]

Step 2: Iterate with i as the first element
Loop: for (i = 0; i < nums.size() - 2; i++)

Case 1: i = 0 → nums[i] = -4
left = 1, right = 5
sum = -4 + (-1) + 2 = -3 < 0 → move left → left = 2
sum = -4 + (-1) + 2 = -3 < 0 → left = 3
sum = -4 + 0 + 2 = -2 < 0 → left = 4
sum = -4 + 1 + 2 = -1 < 0 → left = 5
Loop ends → no triplet.

Case 2: i = 1 → nums[i] = -1
left = 2, right = 5
sum = -1 + (-1) + 2 = 0 ✅ → triplet = [-1, -1, 2]
Store in set → uniqueTriplets = {[-1, -1, 2]}
Move both → left = 3, right = 4
sum = -1 + 0 + 1 = 0 ✅ → triplet = [-1, 0, 1]
Store in set → uniqueTriplets = {[-1, -1, 2], [-1, 0, 1]}
Move both → left = 4, right = 3 → loop ends.

Case 3: i = 2 → nums[i] = -1 (duplicate of previous first element)
Works again, but because of the set, duplicates are automatically avoided.
Case 4: i = 3 → nums[i] = 0
left = 4, right = 5
sum = 0 + 1 + 2 = 3 > 0 → move right = 4
left >= right → stop.

Step 3: Transfer set to result
uniqueTriplets = {[-1, -1, 2], [-1, 0, 1]}

result = [[-1, -1, 2], [-1, 0, 1]]

✅ Final Answer
[[-1, -1, 2], [-1, 0, 1]]
*/
