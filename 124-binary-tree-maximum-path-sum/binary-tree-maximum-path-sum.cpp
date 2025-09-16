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
