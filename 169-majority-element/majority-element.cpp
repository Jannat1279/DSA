class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority =
            nums[0];  // Assume the first element is the majority candidate
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
