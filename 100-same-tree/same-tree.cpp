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

/*
Example:
Tree p:
    1
   / \
  2   3
  
Tree q:
    1
   / \
  2   3
  
🔁 Function Call:
isSameTree(p, q)
🧠 Step-by-Step Execution:
Both p and q are not NULL → values are equal: 1 == 1

Check isSameTree(p->left, q->left)
2 == 2 → check left and right (both NULL) → ✅

Check isSameTree(p->right, q->right)
3 == 3 → check left and right (both NULL) → ✅

All match → return true
✅ Output: true
*/
