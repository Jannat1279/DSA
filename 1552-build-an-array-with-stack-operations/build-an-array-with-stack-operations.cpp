class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream = 1;        // Start streaming numbers from 1 to n
        vector<string> result; // Store sequence of "Push" and "Pop" operations

        int i = 0; // Index to track position in target array

        // Continue until we have processed all elements of target or reached n
        while (i < target.size() && stream <= n) {
            result.push_back("Push"); // Always push the current number (stream)

            if (stream ==
                target[i]) { // If the current number matches target element
                i++;         // Move to next target element
            } else {
                result.push_back("Pop"); // Otherwise, pop it immediately since
                                         // it's not needed
            }

            stream++; // Move to the next number in the stream
        }

        return result; // Return the list of operations
    }
};
