class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // Map to track how many times each player has lost
        unordered_map<int, int> lost;
        
        // Count the number of losses for each player
        for(auto &it : matches) {
            int lose = it[1];    // second element is the loser
            lost[lose]++;        // increment their loss count
        }
        
        vector<int> notLost;  // players who never lost
        vector<int> oneLos;   // players who lost exactly once
        
        // Go through all matches again to collect winners and one-time losers
        for(auto &it : matches) {
            int lose = it[1];  // loser
            int win  = it[0];  // winner
            
            // If this player has exactly one loss, add to oneLos
            if(lost[lose] == 1) {
                oneLos.push_back(lose);
            }
            
            // If this player never appears as a loser, they are undefeated
            // Mark them as "2" in lost to avoid adding them multiple times
            if(lost.find(win) == lost.end()) {
                notLost.push_back(win);
                lost[win] = 2;  
            }
        }
        
        // Sort results in increasing order
        sort(begin(notLost), end(notLost));
        sort(begin(oneLos), end(oneLos));
        
        // Return as a 2D vector: [ [undefeated players], [players with exactly 1 loss] ]
        return {notLost, oneLos};
    }
};
