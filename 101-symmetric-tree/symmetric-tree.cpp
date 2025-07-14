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
    bool check(TreeNode* l, TreeNode* r){
        if(l==NULL && r==NULL)return true;
        if(l==NULL || r==NULL)return false;
        if(l->val==r->val && check(l->left, r->right) && check(l->right, r->left)) return true;
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return check(root->left, root->right);
    }
};

/*
Example:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
This tree is symmetric — the left and right subtrees are mirrors of each other.

✅ Step-by-Step Execution:
We call isSymmetric(root), which internally calls:

check(root->left, root->right)
= check(2, 2)
2 == 2 ✅ → check outer and inner pairs:

check(3, 3) → ✅

check(4, 4) → ✅

All pairs matched → return true
✔️ Final result: true
*/
