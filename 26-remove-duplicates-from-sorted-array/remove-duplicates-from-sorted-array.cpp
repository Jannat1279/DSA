class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; // pointer for placing unique elements
        for(int j = 1; j < nums.size(); j++) { // j scans through the array
            if(nums[i] != nums[j]) { 
                // Found a new unique element
                nums[i+1] = nums[j]; // place it next to the last unique
                i++; // move i forward
            }
        }
        return i + 1; // number of unique elements
    }
};
/*
Example:
nums = [0,0,1,1,1,2,2,3,3,4]

Start: i=0, j=1
Compare nums[0]=0 and nums[1]=0 → same → do nothing.

j=2 → Compare nums[0]=0 and nums[2]=1 → different!
→ Place nums[1]=1, increment i=1.
Array becomes [0,1,1,1,1,2,2,3,3,4].

j=3 → Compare nums[1]=1 and nums[3]=1 → same → skip.

j=5 → Compare nums[1]=1 and nums[5]=2 → different!
→ Place nums[2]=2, i=2.
Array: [0,1,2,1,1,2,2,3,3,4].

Continue until end.
Final array: [0,1,2,3,4, ...] (unique elements in first 5 positions).

Return value = i+1 = 5.
*/
