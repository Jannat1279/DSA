class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;  // Set to store elements we have seen so far
        
        // Traverse through each number in the array
        for(int num : arr) {
            
            // Check if there exists an element that is double of current
            // OR if current is even and its half already exists in the set
            if(s.contains(num * 2) || (num % 2 == 0 && s.contains(num / 2))) {
                return true; // Condition satisfied → return true
            }
            
            // Add current number to the set for future checks
            s.insert(num);
        }
        
        // If no such pair found
        return false;
    }
};
