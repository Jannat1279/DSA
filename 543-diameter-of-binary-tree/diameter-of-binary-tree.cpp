/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Function to compute the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;  // Variable to keep track of the maximum diameter found
        height(root, diameter);  // Compute height while updating diameter
        return diameter;  // Return the final diameter
    }

    // Helper function to compute height of the tree and update diameter
    int height(TreeNode* node, int& diameter) {
        // Base case: If the current node is NULL, return height as 0
        if (!node) return 0;

        // Recursively find the height of the left and right subtrees
        int left = height(node->left, diameter);
        int right = height(node->right, diameter);

        // Update the diameter. It could be the path passing through the current node
        // which is the sum of heights of left and right subtrees
        diameter = max(diameter, left + right);

        // Return the height of the current node which is
        // 1 (for the current node itself) + max height of left or right subtree
        return 1 + max(left, right);
    }
};
