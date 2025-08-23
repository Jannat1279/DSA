class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Map to store frequency of each element in the array
        unordered_map<int,int> mp;
        // Set to track already seen frequencies
        unordered_set<int> st;

        // Count occurrences of each element
        for(int &x:arr){
            mp[x]++;
        }

        // Check if all frequencies are unique
        for(auto &it:mp){
            int freq = it.second; // frequency of current element

            // If frequency already exists in set, return false
            if(st.find(freq) != st.end()) 
                return false;
            
            // Otherwise, insert frequency into the set
            st.insert(freq);
        }

        // If no duplicate frequencies found, return true
        return true;
    }
};
