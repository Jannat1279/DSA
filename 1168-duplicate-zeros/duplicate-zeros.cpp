class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans; // Temporary vector to build the result
        
        // Traverse through each element of arr
        for(int i = 0; i < arr.size(); i++) {
            
            // If ans is already full (same size as arr), stop
            if(ans.size() == arr.size()) break;
            
            if(arr[i] == 0) {
                // If element is 0 → push two zeros into ans
                ans.push_back(0);
                
                // Push another 0 only if ans is not full
                if(ans.size() < arr.size()) {
                    ans.push_back(0);
                }
            } else {
                // Otherwise, just copy the element
                ans.push_back(arr[i]);
            }
        }
        
        // Copy back the modified elements into arr
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = ans[i];
        }
    }
};
