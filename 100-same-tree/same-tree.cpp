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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: If either tree is null, return true only if both are null
        if (p == NULL || q == NULL) {
            return (p == q);  // true if both are NULL, false if only one is
        }

        // Case 2: Check current node values and recursively check left and right subtrees
        return (
            (p->val == q->val) &&                     // values must match
            isSameTree(p->left, q->left) &&           // left subtrees must match
            isSameTree(p->right, q->right)            // right subtrees must match
        );
    }
};
