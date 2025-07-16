/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            // If both p and q are smaller than root, LCA lies in the left subtree
            if (root->val > p->val && root->val > q->val)
                root = root->left;

            // If both p and q are greater than root, LCA lies in the right subtree
            else if (root->val < p->val && root->val < q->val)
                root = root->right;

            // If one is on the left and the other is on the right (or one equals root),
            // then root is the Lowest Common Ancestor
            else
                return root;
        }

        // If tree is empty or nodes not found
        return NULL;
    }
};

/*
Example:

        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

lowestCommonAncestor(root = 6, p = 2, q = 4)
root = 6

Both 2 and 4 are < 6 → go left
root = 2
p = 2, q = 4

One is root itself, other is in right subtree
✅ LCA = 2

*/
