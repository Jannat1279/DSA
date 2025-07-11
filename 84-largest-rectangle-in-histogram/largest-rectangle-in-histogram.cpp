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
                // !s.empty() If stack still has elements, then:
               //s.top() is the index of the nearest smaller bar to the left.
               //So the rectangle extends from s.top() + 1 to i - 1.


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

/*Example
vector<int> heights = {2, 1, 5, 6, 2, 3};

 i = 0 → currHeight = 2
Stack empty → push index 0
🟦 Stack: [0]

✅ i = 1 → currHeight = 1
heights[s.top()] = 2 > 1 → pop index 0

width = i = 1 (since stack is empty)

area = 2 * 1 = 2

maxArea = 2

Push index 1
🟦 Stack: [1]

✅ i = 2 → currHeight = 5
5 > heights[1] = 1 → push
🟦 Stack: [1, 2]

✅ i = 3 → currHeight = 6
6 > 5 → push
🟦 Stack: [1, 2, 3]

✅ i = 4 → currHeight = 2
2 < 6 → pop index 3
width = 4 - 2 - 1 = 1
area = 6 * 1 = 6
maxArea = 6

2 < 5 → pop index 2
width = 4 - 1 - 1 = 2
area = 5 * 2 = 10
maxArea = 10

Push index 4
🟦 Stack: [1, 4]

✅ i = 5 → currHeight = 3
3 > 2 → push
🟦 Stack: [1, 4, 5]

✅ i = 6 (sentinel) → currHeight = 0
0 < 3 → pop index 5
width = 6 - 4 - 1 = 1
area = 3 * 1 = 3

0 < 2 → pop index 4
width = 6 - 1 - 1 = 4
area = 2 * 4 = 8

0 < 1 → pop index 1
stack is empty → width = 6
area = 1 * 6 = 6

Push 6
🟦 Stack: [6]

✅ Final Result:
maxArea = 10

*/
