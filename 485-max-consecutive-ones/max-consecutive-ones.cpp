class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count++;
            else {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        return max(maxCount, count);
    }
};

/*
Example:
vector<int> nums = {1, 1, 0, 1, 1, 1};

| Index | nums\[i] | count | maxCount |
| ----- | -------- | ----- | -------- |
| 0     | 1        | 1     | 0        |
| 1     | 1        | 2     | 0        |
| 2     | 0        | 0     | 2        |
| 3     | 1        | 1     | 2        |
| 4     | 1        | 2     | 2        |
| 5     | 1        | 3     | 2        |

return max(3, 2) = 3

*/
