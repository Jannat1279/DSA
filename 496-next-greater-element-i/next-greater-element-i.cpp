class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>
            ngeMap; // Stores the next greater element for each number in nums2
        stack<int> st; // Monotonic stack to find the next greater element

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int current = nums2[i];

            // Pop elements from the stack that are less than or equal to
            // current
            while (!st.empty() && st.top() <= current) {
                st.pop();
            }

            // If stack is empty, no greater element to the right
            if (st.empty()) {
                ngeMap[current] = -1;
            } else {
                ngeMap[current] =
                    st.top(); // Top of the stack is the next greater
            }

            st.push(current); // Push current element to stack
        }

        // Replace elements in nums1 with their next greater from the map
        // Iterates through each element in nums1

        // Looks up that element in the ngeMap

        //  Replaces the current value in nums1 with its next greater element(as
        //  stored in the map) 
        for (int i = 0; i < nums1.size(); i++) {
        nums1[i] = ngeMap[nums1[i]];
    }

    return nums1;
}
}
;
/*
Example:
nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]

Step 1: Build a Map (from nums2)
From nums2 = [1, 3, 4, 2], we calculate the next greater element for each:

1 → 3 (next greater on right)
3 → 4
4 → no greater element → -1
2 → no greater element → -1

So, we build:
ngeMap:
1 → 3  
3 → 4  
4 → -1  
2 → -1

nums1 = [4, 1, 2]

4 → map[4] = -1 → becomes -1
1 → map[1] = 3 → becomes 3
2 → map[2] = -1 → becomes -1


*/