class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // Step 1: Sort the array so that the elements are in ascending order
        sort(arr.begin(), arr.end());

        // Step 2: Calculate the common difference of the first two elements
        int diff = arr[1] - arr[0];

        // Step 3: Check if the difference between every consecutive pair is the same
        for (int i = 2; i < arr.size(); i++) {
            // If the current difference is not equal to the initial common difference,
            // then it cannot form an arithmetic progression
            if ((arr[i] - arr[i - 1]) != diff) {
                return false;
            }
        }

        // Step 4: If all consecutive differences match, return true
        return true;
    }
};
