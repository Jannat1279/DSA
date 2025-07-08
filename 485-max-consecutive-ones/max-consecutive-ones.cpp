class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxi = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count++;
            else {
                maxi = max(count, maxi);
                // counter is maintained, if 0 is encountered, it is changed to
                // 0 so it doesn't hinder with the other 1's encountered.
                count = 0;
            }
        }
        // We can’t directly return maxi at the end because the array might end
        // with 1s, and in that case, the final count of consecutive 1s might
        // not get added to maxi if we don’t manually compare it after the loop.
        return max(maxi, count);
    }
};
/*
Example:
nums = [1, 1, 0, 1, 1, 1]
At i = 0, nums[i] = 1 → count = 1

At i = 1, nums[i] = 1 → count = 2

At i = 2, nums[i] = 0 →
maxi = max(0, 2) = 2
count = 0

At i = 3, nums[i] = 1 → count = 1

At i = 4, nums[i] = 1 → count = 2

At i = 5, nums[i] = 1 → count = 3
*/
