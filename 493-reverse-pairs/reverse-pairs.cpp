class Solution {
public:
    // Merges two sorted halves [low..mid] and [mid+1..high] of the array
    // Standard merge function used in merge sort
    int merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;            // Temporary array to store merged elements
        int left = low;
        int right = mid + 1;
        int cnt = 0;                 // Not used in this function, kept for consistency

        // Merge elements from both halves in sorted order
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        // Copy remaining elements from the left half
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        // Copy remaining elements from the right half
        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        // Copy sorted elements back to the original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt; // Not used in reverse pair counting
    }

    // Counts reverse pairs (i, j) such that:
    // i < j and arr[i] > 2 * arr[j], where i is in [low..mid] and j is in [mid+1..high]
    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;

        // For each element in the left half, count how many in the right half satisfy the condition
        for (int i = low; i <= mid; i++) {
            // Move right pointer while the condition holds
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) right++;

            // All elements from (mid+1) to (right-1) form a reverse pair with arr[i]
            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    // Recursively applies merge sort and counts reverse pairs during the process
    int mergeSort(vector<int>& arr, int low, int high){
        int cnt = 0;
        if (low >= high) return cnt; // Base case: 1 or no element

        int mid = (low + high) / 2;

        // Count reverse pairs in left and right halves
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);

        // Count reverse pairs across halves (left -> right)
        cnt += countPairs(arr, low, mid, high);

        // Merge the two halves to maintain sorted order
        merge(arr, low, mid, high);

        return cnt;
    }

    // Driver function to initiate merge sort and return total reverse pairs
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
