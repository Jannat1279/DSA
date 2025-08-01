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

/*
Example:
Make all elements of nums = [1, 3, 5] equal
Cost of changing each element is in cost = [1, 2, 1]

🔢 Initial Setup:
left = min(nums) = 1
right = max(nums) = 5

We'll binary search in this range.

🧠 Binary Search Steps:
🔹 First Iteration:
mid = (1 + 5)/2 = 3

Compute:
getCost(nums, cost, 3)
→ |1 - 3| * 1 + |3 - 3| * 2 + |5 - 3| * 1
→ 2*1 + 0*2 + 2*1 = 4

getCost(nums, cost, 4)
→ |1 - 4| * 1 + |3 - 4| * 2 + |5 - 4| * 1
→ 3*1 + 1*2 + 1*1 = 6

✅ Since cost at 3 < cost at 4, go left:
right = mid - 1 = 2
answer = min(4, 6) = 4

🔹 Second Iteration:
mid = (1 + 2)/2 = 1

Compute:

getCost(nums, cost, 1)
→ |1 - 1|*1 + |3 - 1|*2 + |5 - 1|*1
→ 0 + 4 + 4 = 8

getCost(nums, cost, 2)
→ |1 - 2|*1 + |3 - 2|*2 + |5 - 2|*1
→ 1 + 2 + 3 = 6

✅ Since cost at 1 > cost at 2, go right:

left = mid + 1 = 2
answer = min(4, 6) = 4 (no change)

🔹 Third Iteration:
mid = (2 + 2)/2 = 2

Compute:
getCost(nums, cost, 2) → already known: 6
getCost(nums, cost, 3) → already known: 4

✅ Since cost at 2 > cost at 3, go right:

left = 3
answer = min(4, 6) = 4 (no change)

🔹 Fourth Iteration:
mid = (3 + 2)/2 = 2, but now left > right → loop ends

✅ Final Output:
return answer = 4
*/
