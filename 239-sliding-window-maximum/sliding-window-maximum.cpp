class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Max heap: stores pairs of (num, index)
        // The largest number in the current window is always at the top
        priority_queue<pair<int, int>> pq;

        // Stores the maximum of each sliding window
        vector<int> result;

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // Remove elements from the heap that are outside the current window
            // pq.top().second gives the index of the max element
            while (!pq.empty() && pq.top().second <= i - k)
                pq.pop();

            // Add the current element and its index into the max heap
            pq.push({nums[i], i});

            // If the window has reached size k, record the max (which is at the
            // top of the heap)
            if (i >= k - 1)
                result.push_back(pq.top().
                first);
        }

        // Return the result which contains max of every window of size k
        return result;
    }
};
