class Solution {
public:
     int longestConsecutive(vector<int>& nums) {
     
        int n=nums.size();
        unordered_set<int> st;
        
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        
        int maxi=0;
        
        for(auto i:st){
            
            if(st.count(i-1))continue;
            int len=1;
            
            while(st.count(i+len))len++;
            
            maxi=max(maxi,len);
        }
        return maxi;
        
    }
};