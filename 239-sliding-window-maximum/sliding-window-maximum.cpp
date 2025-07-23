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
                result.push_back(pq.top().first);
        }

        // Return the result which contains max of every window of size k
        return result;
    }
};

/*
Example:
nums = [1, 3, -1, -3, 5, 3, 6, 7]
k = 3

✅ Objective:
Find the maximum in every sliding window of size 3.
We’ll use a max heap (priority queue storing {value, index}) to track the largest value in each window.

🪜 Steps:
🔁 i = 0:
Add {1, 0} to heap.
Window not full yet (need at least k = 3 elements).
⏳ Result: []

🔁 i = 1:
Add {3, 1} to heap.
Heap now: [(3,1), (1,0)]
Window still not full.
⏳ Result: []

🔁 i = 2:
Add {-1, 2} to heap.
Heap now: [(3,1), (1,0), (-1,2)]
Now i = 2, so i >= k - 1 → 2 >= 2 → Window full.
Top of heap = 3 → max of window [1, 3, -1]
✅ Result: [3]

🔁 i = 3:
Add {-3, 3} to heap.
Now we check if top element is outside the window:
Index at top = 1 → still inside window [1, 3] (from i=1 to i=3).
Top is 3 again → max of window [3, -1, -3]
✅ Result: [3, 3]

🔁 i = 4:
Add {5, 4} to heap.
Now top = 5 → in window [ -1, -3, 5 ]
Heap contains outdated index 1 → it’s removed.
Top is now 5 → max of window [-1, -3, 5]
✅ Result: [3, 3, 5]

🔁 i = 5:
Add {3, 5} to heap.
Top is still 5 (index 4, valid).
max of window [-3, 5, 3]
✅ Result: [3, 3, 5, 5]

🔁 i = 6:
Add {6, 6} to heap.
Top becomes 6
max of window [5, 3, 6]
✅ Result: [3, 3, 5, 5, 6]

🔁 i = 7:
Add {7, 7} to heap.
Top becomes 7
max of window [3, 6, 7]
✅ Final Result: [3, 3, 5, 5, 6, 7]


*/
