class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int stream = 1;        // Start streaming numbers from 1 to n
        vector<string> result; // Store sequence of "Push" and "Pop" operations

        int i = 0; // Index to track position in target array

        // Continue until we have processed all elements of target or reached n
        while (i < target.size() && stream <= n) {
            result.push_back("Push"); // Always push the current number (stream)

            if (stream == target[i]) { // If the current number matches target element
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

/*
Example:
Given:

target = [2,3,4]

n = 4

Goal:
Simulate reading numbers from 1 to 4, and build target array using only "Push" and "Pop" operations.

Step-by-step explanation:
Stream number 1:
Push 1 onto the stack -> Operation: "Push"
1 is NOT in target at the current position (2), so immediately Pop it -> Operation: "Pop"
Stack is empty now.

Stream number 2:
Push 2 -> "Push"
2 matches target's first element -> Keep it (do NOT pop)

Move to next target element (3).
Stream number 3:
Push 3 -> "Push"
3 matches next target element -> Keep it

Move to next target element (4).
Stream number 4:
Push 4 -> "Push"
4 matches next target element -> Keep it

Target fully built.

Final sequence of operations:
"Push", "Pop", "Push", "Push", "Push"
*/
