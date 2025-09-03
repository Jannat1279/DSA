class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];  // Assume the first element is the majority candidate
        int vote = 1; // Initialize vote count for the current candidate

        // Start from the second element
        for (int i = 1; i < nums.size(); i++) {

            // If current vote count drops to zero, choose a new candidate
            if (vote == 0) {
                majority = nums[i];
                vote = 1;
            }
            // If current number matches the current majority candidate,
            // increment vote
            else if (majority == nums[i]) {
                vote++;
            }
            // If current number doesn't match the candidate, decrement vote
            else {
                vote--;
            }
        }

        // The element stored in 'majority' is the majority element
        // (Assuming the problem guarantees that one exists)
        return majority;
    }
};

/*
Example:

nums = [2, 2, 1, 1, 1, 2, 2]
We want to find the majority element — the one that appears more than ⌊n / 2⌋ times.
In this case, the length n = 7, so we are looking for the element that appears > 3 times.

🔁 Step-by-Step Execution:
| Index | nums [i] | majority | vote | Action                                                              |
| ----- | -------- | -------- | ---- | ------------------------------------------------------------------- |
| 0     | 2        | 2        | 1    | Initialize with first element                                       |
| 1     | 2        | 2        | 2    | Same as majority → vote++                                           |
| 2     | 1        | 2        | 1    | Different from majority → vote--                                    |
| 3     | 1        | 2        | 0    | Different again → vote--, becomes 0 → new candidate in next step    |
| 4     | 1        | 1        | 1    | vote was 0 → set majority = 1, vote = 1                             |
| 5     | 2        | 1        | 0    | Different from majority → vote--, becomes 0 → new candidate in next |
| 6     | 2        | 2        | 1    | vote was 0 → set majority = 2, vote = 1                             |


✅ Final Output:
return majority = 2;
*/
