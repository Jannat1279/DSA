class Solution {
public:
    // Helper function to check if we can complete at least 'totalTrips' within 'givenTime'
    bool possible(vector<int>& time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        
        // Each bus with time 't' can make (givenTime / t) trips in 'givenTime'
        for(int &t : time) {
            actualTrips += givenTime / t;
        }
        
        // If total trips made by all buses >= required trips, it's possible
        return actualTrips >= totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        
        // Left bound: minimum possible time (at least 1 unit of time)
        long long l = 1;
        
        // Right bound: worst-case = fastest bus × totalTrips  
        // (since the fastest bus alone could finish all trips)
        long long r = (long long) *min_element(begin(time), end(time)) * totalTrips;
        
        // Apply Binary Search on time
        while(l < r) {
            long long mid_time = l + (r - l) / 2;
            
            // If it's possible to finish required trips in mid_time,
            // then try to minimize (move right bound to mid_time)
            if(possible(time, mid_time, totalTrips)) {
                r = mid_time;
            } 
            // Otherwise, we need more time, so move left bound up
            else {
                l = mid_time + 1;
            }
        }
        
        // 'l' (or 'r') will hold the minimum time required
        return l;
    }
};
