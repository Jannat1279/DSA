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

/*
Example:
vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
Index:     0 1 2 3 4 5 6 7 8 9 10 11
Height:    0 1 0 2 1 0 1 3 2 1  2  1

🔁 Step-by-step Execution:
Initialize:

i = 0, j = 11
maxLeft = 0, maxRight = 0
water = 0

height[i] < height[j] → 0 < 1
maxLeft = max(0, 0) = 0
Water trapped = 0 - 0 = 0
i++ → i = 1

height[i] < height[j] → 1 < 1 → false
maxRight = max(0, 1) = 1
Water trapped = 1 - 1 = 0
j-- → j = 10

height[i] < height[j] → 1 < 2
maxLeft = max(0, 1) = 1
Water trapped = 1 - 1 = 0
i++ → i = 2

height[i] < height[j] → 0 < 2
maxLeft = max(1, 0) = 1
Water trapped = 1 - 0 = 1 ✅
water = 1
i++ → i = 3

height[i] < height[j] → 2 < 2 → false
maxRight = max(1, 2) = 2
Water trapped = 2 - 2 = 0
j-- → j = 9

height[i] < height[j] → 2 < 1 → false
maxRight = max(2, 1) = 2
Water trapped = 2 - 1 = 1 ✅
water = 2
j-- → j = 8

height[i] < height[j] → 2 < 2 → false
maxRight = max(2, 2) = 2
Water trapped = 2 - 2 = 0
j-- → j = 7

height[i] < height[j] → 2 < 3
maxLeft = max(1, 2) = 2
Water trapped = 2 - 2 = 0
i++ → i = 4

height[i] < height[j] → 1 < 3
maxLeft = max(2, 1) = 2
Water trapped = 2 - 1 = 1 ✅
water = 3
i++ → i = 5

height[i] < height[j] → 0 < 3
maxLeft = max(2, 0) = 2
Water trapped = 2 - 0 = 2 ✅
water = 5
i++ → i = 6

height[i] < height[j] → 1 < 3
maxLeft = max(2, 1) = 2
Water trapped = 2 - 1 = 1 ✅
water = 6
i++ → i = 7

Now i == j, loop ends.

✅ Final Output:
return 6;
*/
