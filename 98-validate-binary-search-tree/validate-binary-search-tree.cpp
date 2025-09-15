class Solution {
public:
    // Helper function that checks whether the binary tree rooted at 'root'
    // is a valid BST given the allowed value range (min, max).
    bool isValidBST(TreeNode* root, long min, long max){
        // Base case: an empty tree is always valid
        if(root == NULL) return true;

        // Current node's value must lie strictly between min and max
        if(root->val >= max || root->val <= min) return false;

        // Recursively check the left subtree with an updated max bound
        // and the right subtree with an updated min bound
        return isValidBST(root->left, min, root->val) &&
               isValidBST(root->right, root->val, max);
    }

    // Main function: starts the recursion with the widest possible bounds
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};
