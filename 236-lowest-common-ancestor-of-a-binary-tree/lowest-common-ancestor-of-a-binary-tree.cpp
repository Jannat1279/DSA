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

/*
Example:
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4
Let’s find the LCA of 7 and 4.

🔁 Recursive Call Stack:
We start at the root (3) and go deeper until we find both nodes.

1. Call: lowestCommonAncestor(3, 7, 4)
3 ≠ 7 and 3 ≠ 4 → keep going
Recurse left and right

2. Call: lowestCommonAncestor(5, 7, 4) (left of 3)
5 ≠ 7 and 5 ≠ 4 → recurse further

3. Call: lowestCommonAncestor(6, 7, 4) (left of 5)
6 ≠ 7 or 4
6 has no children → return NULL

✅ Left of 5 returns NULL

4. Call: lowestCommonAncestor(2, 7, 4) (right of 5)
2 ≠ 7 or 4 → recurse further

5. Call: lowestCommonAncestor(7, 7, 4) (left of 2)
Found p = 7 → return 7

6. Call: lowestCommonAncestor(4, 7, 4) (right of 2)
Found q = 4 → return 4

✅ Node 2: Has both left = 7 and right = 4 → returns 2
🚀 Back Up the Stack:
lowestCommonAncestor(5, 7, 4) → left = NULL, right = 2 → return 2
lowestCommonAncestor(3, 7, 4) → left = 2, right = NULL → return 2

✅ Final Result:
LCA(7, 4) = 2
*/
