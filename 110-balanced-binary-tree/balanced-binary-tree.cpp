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

/*
Example:
        1
       / \
      2   3
     /
    4

🔁 Step-by-Step Function Execution:
Call: isBalanced(1)
Call height(2)
Call height(4) → left and right are NULL → height = 1
Call height(NULL) → 0
Height of node 2 = 1 + max(1, 0) = 2
Call height(3) → no children → height = 1
Difference = abs(2 - 1) = 1 → ✅ still balanced

Now check subtrees:
isBalanced(2)
Call height(4) = 1
Call height(NULL) = 0
Difference = 1 → ✅

Call isBalanced(4) → returns true (leaf)
Call isBalanced(NULL) → true
So node 2 is ✅ balanced

isBalanced(3) → returns true (leaf)

✅ Final Output:
true
*/
