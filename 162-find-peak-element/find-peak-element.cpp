// time - O(log n), space - O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        // Binary search to find a peak
        while (l < r) {
            int mid = (l + r) / 2;

            // If the next element is greater, the peak lies on the right
            if (nums[mid + 1] > nums[mid]) {
                l = mid + 1;
            } 
            // If the next element is smaller or equal, the peak is on the left or could be mid
            else {
                r = mid;
            }
        }

        // At the end of loop, l == r, pointing to a peak element
        return r;
    }
};
/*
Example:
vector<int> nums = {1, 2, 1, 3, 5, 6, 4};

The peak(s) can be at index:
1 (value 2), since 2 > 1 and 2 > 1
5 (value 6), since 6 > 5 and 6 > 4

The function can return any peak.

🧠 Step-by-step Execution:
l = 0, r = 6  // full range of nums
1st Iteration:
mid = (0 + 6) / 2 = 3
nums[mid] = 3
nums[mid + 1] = 5
Since 5 > 3 → move right → l = mid + 1 = 4

2nd Iteration:
l = 4, r = 6
mid = (4 + 6) / 2 = 5
nums[mid] = 6
nums[mid + 1] = 4
Since 4 < 6 → move left → r = mid = 5

3rd Iteration:
l = 4, r = 5
mid = (4 + 5) / 2 = 4
nums[mid] = 5
nums[mid + 1] = 6

Since 6 > 5 → move right → l = mid + 1 = 5
End Condition:
Now l == r == 5, and nums[5] = 6 → a peak element
*/
