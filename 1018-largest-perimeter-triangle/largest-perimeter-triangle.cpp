class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Step 1: Sort the array so sides are in non-decreasing order
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        // Step 2: Iterate from the largest side towards the front
        // We check triplets (nums[i], nums[i+1], nums[i+2]) in descending order
        for (int i = n - 3; i >= 0; i--) {
            // Triangle inequality condition:
            // Sum of two smaller sides must be greater than the largest side
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                // If valid, return the perimeter of this triangle
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        
        // Step 3: If no valid triangle can be formed, return 0
        return 0;
    }
};
