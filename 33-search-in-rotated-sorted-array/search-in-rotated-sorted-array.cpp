class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, end = n - 1;
        while (s <= end) {
            int mid = (s + end) / 2;
            if (nums[mid] == target)
                return mid;
            // left half is sorted
            if (nums[s] <= nums[mid]) {
                if (nums[mid] > target && target >= nums[s]) {
                    end = mid - 1;
                }

                else {
                    s = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[end]) {
                    s = mid + 1;
                }

                else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};