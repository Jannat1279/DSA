class Solution {
public:
    // Function to find the maximum path sum in a binary tree
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;  // stores the global maximum path sum
        maxPathDown(root, maxi);
        return maxi;        // return the overall maximum path sum
    }

    // Helper function: returns the maximum path sum that can be extended upwards from this node
    int maxPathDown(TreeNode* node, int &maxi) {
        if (node == NULL) return 0;   // base case: no contribution from NULL nodes

        // Recursively calculate max path sum from left and right children
        // If the contribution is negative, we take 0 (ignore that path)
        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));

        // Update the global maximum:
        // Case 1: the max path passes through this node including both left and right
        // left + right + node->val = max path sum passing through the current node
        maxi = max(maxi, left + right + node->val);

        // Return the max path sum for one side + current node’s value
        // This value can be extended to parent (cannot include both left & right, only one path upward)
        return max(left, right) + node->val;
    }
};

/*
Example:
       -10
       /  \
     9    20
         /  \
        15   7

Steps:

Start at root -10.
For node 9 → left=0, right=0 → maxi = max(-∞, 0+0+9) = 9. Returns 9.
For node 15 → maxi = max(9, 0+0+15) = 15. Returns 15.
For node 7 → maxi = max(15, 0+0+7) = 15. Returns 7.
For node 20 → left=15, right=7.
maxi = max(15, 15+7+20=42) = 42.
Returns max(15,7)+20 = 35.
For root -10 → left=9, right=35.
maxi = max(42, 9+35-10=34) = 42.
Returns 25.

👉 Final Answer = 42 (path 15 → 20 → 7)
*/
