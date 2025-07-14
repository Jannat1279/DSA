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
        if(root==NULL)return NULL;
        if(root->val==p->val || root->val==q->val)return root;
        // Recursive call for both left and right
        TreeNode* l=lowestCommonAncestor(root->left, p, q);
        TreeNode* r=lowestCommonAncestor(root->right, p, q);

        //Both are non null(left and right), different sub-tree 
        if(l&&r)return root;

        // Same subtree
        return l?l:r;
    }
};