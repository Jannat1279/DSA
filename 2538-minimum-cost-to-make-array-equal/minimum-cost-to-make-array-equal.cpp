class Solution {
public:
    typedef long long ll;

    // Helper function to calculate total cost of making all elements equal to
    // 'target'
    ll getCost(vector<int>& nums, vector<int>& cost, int target) {
        ll result = 0;
        for (int i = 0; i < nums.size(); i++) {
            // Accumulate the cost of changing nums[i] to target
            result += 1LL * abs(nums[i] - target) * cost[i];
        }
        return result;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll answer = LLONG_MAX; // Initialize answer with maximum possible value

        // Set the binary search range to [min(nums), max(nums)]
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        // Binary search on the answer (target value)
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Calculate total cost for mid and mid + 1
            ll cost1 = getCost(nums, cost, mid);
            ll cost2 = getCost(nums, cost, mid + 1);

            // Store the minimum cost so far
            answer = min(cost1, cost2);

            // Since the cost function is convex:
            // If cost1 < cost2, move search space to the left
            if (cost1 < cost2) {
                right = mid - 1;
            } else {
                // Else, move to the right
                left = mid + 1;
            }
        }

        // Final answer is the minimum cost found
        return (answer == LLONG_MAX) ? 0 : answer;
    }
};
