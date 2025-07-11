class Solution {
public:
// Two-pointer approach to calculate trapped rainwater
    int trap(vector<int>& height) {
        int i = 0;                      // Pointer starting from the left end
        int j = height.size() - 1;      // Pointer starting from the right end
        int maxLeft = 0;                // Tracks the maximum height to the left of current `i`
        int maxRight = 0;               // Tracks the maximum height to the right of current `j`
        int water = 0;                  // Stores total amount of trapped water

        // Process until the two pointers meet
        while (i < j) {
            // If the height at the left is less than the right,
            // water is trapped based on the left side.
            if (height[i] < height[j]) {
                maxLeft = max(maxLeft, height[i]);                  // Update max on the left
                water += maxLeft - height[i];                       // Water trapped = maxLeft - current height
                i++;                                                // Move left pointer to the right
            }
            else {
                // Otherwise, water is trapped based on the right side
                maxRight = max(maxRight, height[j]);               // Update max on the right
                water += maxRight - height[j];                     // Water trapped = maxRight - current height
                j--;                                               // Move right pointer to the left
            }
        }

        return water;  // Return the total trapped water
    }
};