class Solution {
public:
    
    // Helper function: checks if Koko can eat all bananas
    // at speed 'givenHour' within 'h' hours.
    bool canEatAll(vector<int>& piles, int givenHour, int h) {
        int actualHour = 0;
        
        // For each pile of bananas
        for(int &x : piles) {
            // Time taken to eat pile x at speed 'givenHour' = ceil(x / givenHour)
            actualHour += x / givenHour;
            
            // If division leaves a remainder, she needs one extra hour
            if(x % givenHour != 0)
                actualHour++;
        }
        
        // Return true if Koko can finish within 'h' hours
        return actualHour <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        // Left bound: slowest possible speed (1 banana/hour)
        int l = 1;
        // Right bound: fastest needed speed = size of the largest pile
        // (if she eats that whole pile in one hour)
        int r = *max_element(begin(piles), end(piles));
        
        // Binary search for minimum valid eating speed
        while(l < r) {
            int mid = l + (r - l) / 2;
            
            // If Koko can eat all bananas at speed 'mid',
            // try smaller speed (move right bound down)
            if(canEatAll(piles, mid, h)) {
                r = mid;
            } 
            // Otherwise, increase the speed (move left bound up)
            else {
                l = mid + 1;
            }
        }
        
        // 'l' (or 'r') is the minimum eating speed
        return l;
    }
};
