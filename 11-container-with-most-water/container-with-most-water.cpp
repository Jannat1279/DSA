// time - O(n), space - O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;             // To store the maximum water area
        int left = 0, right = n - 1; // Two-pointer approach: start from both ends

        // Loop until the two pointers meet
        while (left <= right) {
            // Find the limiting height (shorter side) and calculate width
            int minHeight = min(height[left], height[right]);
            int width = right - left;

            // Calculate current area = minHeight * width
            int area = minHeight * width;

            // Update maximum area if the current one is larger
            maxArea = max(area, maxArea);

            // Move the pointer pointing to the smaller line
            // Because the area is limited by the smaller line,
            // moving it may help us find a taller line for a bigger area.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        // Return the maximum area found
        return maxArea;
    }
};
