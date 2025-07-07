class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, maxSum = 0;

        // Step 1: Initially take the first 'k' cards from the left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        // Set the initial maxSum as the sum of the first 'k' cards
        maxSum = lsum;

        // Set the right index to the last card
        int rindex = cardPoints.size() - 1;

        // Step 2: Try replacing cards from the left end with cards from the right
        // One by one, remove cards from the left sum and add from the right
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];         // Remove one card from the left
            rsum += cardPoints[rindex];    // Add one card from the right
            rindex--;                      // Move the right pointer left
            maxSum = max(maxSum, lsum + rsum);  // Update max if the new total is greater
        }

        // Step 3: Return the maximum score obtained
        return maxSum;
    }
};
/*
Example:
cardPoints = [1, 2, 3, 4, 5, 6, 1]
k = 3
Left pick: [1, 2, 3] → sum = 6

| Step | Left Cards Removed | Right Cards Added | lsum | rsum | Total (lsum + rsum) | maxSum |
| ---- | ------------------ | ----------------- | ---- | ---- | ------------------- | ------ |
| 1    | 3 (index 2)        | 1 (index 6)       | 3    | 1    | 4                   | 6      |
| 2    | 2 (index 1)        | 6 (index 5)       | 1    | 7    | 8                   | 8      |
| 3    | 1 (index 0)        | 5 (index 4)       | 0    | 12   | 12                  | 12     |

Maximum Score = 12

*/
