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
/*
nums = [100, 4, 200, 1, 3, 2]
st = {1, 2, 3, 4, 100, 200}

Step : Iterate through the set
For i = 1
st.count(0) → false ⇒ valid start of sequence

len = 1

st.count(2) → true ⇒ len = 2

st.count(3) → true ⇒ len = 3

st.count(4) → true ⇒ len = 4

st.count(5) → false ⇒ stop

maxi = max(0, 4) = 4 ✅

For i = 2
st.count(1) → true ⇒ skip (not start of sequence)

For i = 3
st.count(2) → true ⇒ skip

For i = 4
st.count(3) → true ⇒ skip

For i = 100
st.count(99) → false ⇒ valid start

len = 1, st.count(101) → false ⇒ stop

maxi = max(4, 1) = 4

For i = 200
st.count(199) → false ⇒ valid start

len = 1, st.count(201) → false ⇒ stop

maxi = max(4, 1) = 4
*/
