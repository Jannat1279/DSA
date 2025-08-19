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

/*
Example:
groupSizes = [3,3,3,3,3,1,3]

This means:

Person 0 wants to be in a group of size 3
Person 1 wants to be in a group of size 3
Person 2 wants to be in a group of size 3
Person 3 wants to be in a group of size 3
Person 4 wants to be in a group of size 3
Person 5 wants to be in a group of size 1
Person 6 wants to be in a group of size 3

Step-by-Step Execution
Start with empty result = [] and mp = [[] ...]

i=0, groupSizes[0]=3
→ Add person 0 to mp[3] → mp[3] = [0]

i=1, groupSizes[1]=3
→ Add person 1 → mp[3] = [0,1]

i=2, groupSizes[2]=3
→ Add person 2 → mp[3] = [0,1,2]
→ Size reached 3 → Move [0,1,2] into result
→ Reset mp[3] = []
→ result = [[0,1,2]]

i=3, groupSizes[3]=3
→ Add person 3 → mp[3] = [3]

i=4, groupSizes[4]=3
→ Add person 4 → mp[3] = [3,4]

i=5, groupSizes[5]=1
→ Add person 5 → mp[1] = [5]
→ Size reached 1 → Move [5] into result
→ Reset mp[1] = []
→ result = [[0,1,2],[5]]

i=6, groupSizes[6]=3
→ Add person 6 → mp[3] = [3,4,6]
→ Size reached 3 → Move [3,4,6] into result
→ Reset mp[3] = []
→ result = [[0,1,2],[5],[3,4,6]]

*/
