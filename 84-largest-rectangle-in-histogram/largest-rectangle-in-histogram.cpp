class Solution {
public:
   int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;            // Stores the maximum area found so far
        stack<int> s;               // Stack to keep indices of increasing bar heights

        // Iterate through all bars including a sentinel (0 height) at the end
        for (int i = 0; i <= n; i++) {
            // For the last iteration, we use 0 height to flush the stack
            int currHeight = (i == n) ? 0 : heights[i];

            // While current height is less than the height at the top of the stack,
            // we need to calculate area for the bar at the top of the stack
            while (!s.empty() && currHeight < heights[s.top()]) {
                int top = s.top();          // Index of the bar to calculate area for
                s.pop();                    // Remove it as we are calculating its final area

                // If the stack is empty, it means the popped bar was the smallest so far,
                // so its width extends from index 0 to i
                // Otherwise, width = i - index after popping - 1
                int width = s.empty() ? i : i - s.top() - 1;

                // Area = height of the bar * calculated width
                int area = heights[top] * width;

                // Update max area if this is larger
                maxArea = max(maxArea, area);
            }

            // Push current index to stack
            s.push(i);
        }

        return maxArea;
    }
};