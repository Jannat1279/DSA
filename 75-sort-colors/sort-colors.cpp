class Solution {
public:
    // Helper function to swap elements at indices i and j in the array
    void swaps(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void sortColors(vector<int>& nums) {
        int start = 0;              // Pointer for the position of next 0
        int end = nums.size() - 1;  // Pointer for the position of next 2
        int curPos = 0;             // Current index being processed

        // Loop runs until curPos crosses the end pointer
        while (curPos <= end) {
            // Case 1: Current element is 0
            // Swap it with the element at 'start', and move both pointers forward
            if (nums[curPos] == 0) {
                swaps(nums, curPos++, start++);
            }
            // Case 2: Current element is 2
            // Swap it with the element at 'end', and move 'end' backward
            // Do NOT move curPos because the swapped value must be re-evaluated
            else if (nums[curPos] == 2) {
                swaps(nums, curPos, end--);
            }
            // Case 3: Current element is 1
            // No swap needed, just move forward
            else {
                curPos++;
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;   //denotes for 0
        int j = 0;   //denotes for 1
        int k = n-1; //denotes for 2
        
        while ( j <= k) {
            if(nums[j] == 1) {
                j++;
            } else if(nums[j] == 2) {
                swap(nums[j], nums[k]);
                k--;
            } else { //nums[j] == 0
                swap(nums[j], nums[i]);
                i++;
                j++;
            }
        }
    }
};


/*
Example:
🔹 Example Input:
nums = [2, 0, 2, 1, 1, 0]

🔹 Initial State:
start = 0 → points to where the next 0 should go
end = 5 → points to where the next 2 should go
curPos = 0 → current index being evaluated

| Step | curPos | nums [curPos] | Action                      | Array After Action  | start | end | curPos |
| ---- | ------ | ------------- | --------------------------- | ------------------- | ----- | --- | ------ |
| 1    | 0      | 2             | Swap with `end` (index 5)   |  [0, 0, 2, 1, 1, 2] | 0     | 4   | 0      |
| 2    | 0      | 0             | Swap with `start` (index 0) |  [0, 0, 2, 1, 1, 2] | 1     | 4   | 1      |
| 3    | 1      | 0             | Swap with `start` (index 1) |  [0, 0, 2, 1, 1, 2] | 2     | 4   | 2      |
| 4    | 2      | 2             | Swap with `end` (index 4)   |  [0, 0, 1, 1, 2, 2] | 2     | 3   | 2      |
| 5    | 2      | 1             | Just move curPos forward    |  [0, 0, 1, 1, 2, 2] | 2     | 3   | 3      |
| 6    | 3      | 1             | Just move curPos forward    |  [0, 0, 1, 1, 2, 2] | 2     | 3   | 4      |

*/
