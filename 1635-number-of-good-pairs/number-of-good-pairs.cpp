class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;  
        unordered_map<int, int> mp;  // map to count frequency of each number
        
        // Count occurrences of each number in nums
        for(int &num : nums) {
            mp[num]++;
        }
        
        // For each number's frequency, calculate the number of good pairs
        for(auto &it : mp) {
            int count = it.second;  
            
            // Formula for combinations: choosing 2 from 'count' elements
            // countC2 = count * (count - 1) / 2
            result += (count * (count - 1)) / 2;
        }
        
        return result;  // return total number of good pairs
    }
};
