class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        // Binary search to find the peak element in the mountain array
        while (low < high) {
            int mid = (low + high) / 2;

            // If the middle element is less than its next element,
            // the peak lies to the right (ascending slope)
            if (arr[mid] < arr[mid + 1]) {
                low = mid + 1; // move right
            } else {
                // If the middle element is greater than or equal to the next,
                // we're on the descending side or at the peak
                high = mid; // move left (but include mid)
            }
        }

        // When low == high, we've found the peak index
        return low;
    }
};
