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
