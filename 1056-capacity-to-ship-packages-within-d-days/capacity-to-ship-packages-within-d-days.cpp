class Solution {
public:
    // Helper function to calculate how many days it would take
    // to ship all weights with a given capacity (cap)
    int findDays(vector<int>& weights, int cap) {
        int days = 1; // At least one day is needed
        int load = 0; // Current weight being loaded on the ship for the day
        int n = weights.size();

        for (int i = 0; i < n; i++) {
            // If adding the current weight exceeds capacity, start a new day
            if (load + weights[i] > cap) {
                days += 1;         // New day needed
                load = weights[i]; // Start new day's load with current weight
            } else {
                load += weights[i]; // Add current weight to today's load
            }
        }

        return days; // Total number of days required with this capacity
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // Minimum possible capacity is the max weight (we must carry the
        // heaviest item)
        int left = *max_element(weights.begin(), weights.end());

        // Maximum possible capacity is the sum of all weights (ship all in 1
        // day)
        int right = accumulate(weights.begin(), weights.end(), 0);

        // Binary search to find the minimum capacity that allows shipping
        // within 'days'
        while (left <= right) {
            int mid = left + (right - left) / 2; // Try this capacity

            int noOfDays = findDays(weights, mid); // How many days needed with this capacity

            if (noOfDays <= days) {
                // Try to minimize the capacity
                right = mid - 1;
            } else {
                // Need more capacity → move right
                left = mid + 1;
            }
        }

        // 'left' now holds the minimum capacity needed
        return left;
    }
};
