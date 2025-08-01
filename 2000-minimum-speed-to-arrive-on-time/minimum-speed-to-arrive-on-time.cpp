class Solution {
public:
    // Helper function to calculate the total time taken to travel given distances at a certain speed
    double possible(vector<int>& dist, int speed) {
        double time = 0.0;
        int n = dist.size();

        // For all trips except the last, round up the time to the next integer (must depart on the hour)
        for (int i = 0; i < n - 1; i++) {
            double t = (double)dist[i] / (double)speed;
            time += ceil(t); // because of departure constraints
        }

        // For the last trip, exact time is allowed (no rounding needed)
        time += (double)dist[n - 1] / (double)speed;

        return time; // total time to reach destination at given speed
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1;           // minimum possible speed
        int r = 1e7;         // maximum speed constraint (as per problem limits)
        int minSpeed = -1;   // default if it's not possible to reach on time

        // Binary search on speed
        while (l <= r) {
            int mid = l + (r - l) / 2; // try a mid speed

            // If time taken at mid speed is within allowed time
            if (possible(dist, mid) <= hour) {
                minSpeed = mid;   // update answer
                r = mid - 1;      // try to find a smaller speed
            } else {
                l = mid + 1;      // need to speed up
            }
        }

        return minSpeed; // return the minimum speed that allows on-time arrival
    }
};

/*
Example:
dist = [1, 3, 2]
hour = 6.0

🔹 Try speed = 1
Call possible(dist, 1):
Segment 1: 1 / 1 = 1.0 → ceil(1.0) = 1
Segment 2: 3 / 1 = 3.0 → ceil(3.0) = 3
Segment 3: 2 / 1 = 2.0 → no rounding

Total time = 1 + 3 + 2 = 6.0 ✅

So, it’s possible with speed = 1.

🔍 Binary Search Trace:
We want the minimum speed, so we continue searching left.

Initial bounds:
left = 1, right = 1e7
minSpeed = -1

1st Iteration:
mid = (1 + 1e7) / 2 = 5000000
possible(dist, 5000000) → Time ≈ 1 (all segments near 0 time, but ceil makes 2 of them = 1)
So time ≈ 1 + 1 + tiny ≈ 2.0 → ✅

Update:
minSpeed = 5000000
Try smaller → right = 4999999

Continue this binary search...

Eventually, when mid = 1, you find:

possible(dist, 1) = 6.0 → ✅

So keep updating minSpeed to smaller and smaller

✅ Final Answer:
Minimum speed = 1


*/
