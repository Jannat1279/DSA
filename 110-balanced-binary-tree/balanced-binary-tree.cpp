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
    // Helper function to compute the height of a subtree
    int height(TreeNode* root) {
        if (root == NULL) return 0;  // Base case: empty tree has height 0

        // Height is 1 (for current node) + max height of left and right subtrees
        return 1 + max(height(root->left), height(root->right));
    }

    // Main function to check if the tree is height-balanced
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;  // An empty tree is balanced

        // Compute height difference of left and right subtrees
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // If height difference > 1, the tree is not balanced at this node
        if (abs(leftHeight - rightHeight) > 1) return false;

        // Recursively check if left and right subtrees are balanced
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
