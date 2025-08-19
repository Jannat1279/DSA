class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();   // Total number of people
        
        // mp[k] will store the list of people who belong to a group of size 'k'
        vector<vector<int>> mp(n+1);
        
        // Final result storing all valid groups
        vector<vector<int>> result;
        
        // Iterate through each person
        for(int i = 0; i < n; i++) {
            
            int l = groupSizes[i];   // Required group size for this person
            
            mp[l].push_back(i);      // Add this person to the group of size 'l'
            
            // If we have enough people to form a complete group of size 'l'
            if(mp[l].size() == l) {
                result.push_back(mp[l]);  // Add this group to the result
                mp[l] = {};               // Reset the list for future groups of size 'l'
            }
        }
        
        return result;   // Return all grouped people
    }
};
