class Solution {
public:
    // Alias for a pair<int, int>, where
    // first -> frequency of the number
    // second -> the number itself
    typedef pair<int,int> p;  
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Min-heap (priority queue) to store top K elements by frequency
        // Using 'greater<p>' makes it a min-heap based on the first value (frequency)
        priority_queue<p, vector<p>, greater<p>> pq;

        // Hash map to count frequency of each number
        unordered_map<int,int> mp;

        // Count frequency of each number in nums
        for(int i : nums){
            mp[i]++;
        }

        // Push each unique number and its frequency into the min-heap
        for(auto it : mp){
            pq.push({it.second, it.first});  // {frequency, number}
            
            // Keep only top K elements in the heap
            if(pq.size() > k) pq.pop();
        }

        // Collect results from the heap
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second); // store the number
            pq.pop();
        }

        return result;  // Top K frequent elements
    }
};
