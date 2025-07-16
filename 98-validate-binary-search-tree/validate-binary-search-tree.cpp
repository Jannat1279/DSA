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
    bool isValidBST(TreeNode* root, long min, long max){
        if(root==NULL)return true;
        if(root->val>=max || root->val<=min)return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};

/*
Example:
        10
       /  \
      5    15
          /  \
        12    20

Step-by-Step Validation:
We start with the full range (-∞, ∞):

Node 10:
10 > LONG_MIN ✅
10 < LONG_MAX ✅
→ Go left and right

Left Subtree of 10:
Node 5:
Range: (-∞, 10)
5 > LONG_MIN ✅
5 < 10 ✅
→ 5 has no children → ✅ return true

Right Subtree of 10:
Node 15:
Range: (10, ∞)
15 > 10 ✅
15 < LONG_MAX ✅
→ Check left and right children

Node 12:
Range: (10, 15)
12 > 10 ✅
12 < 15 ✅
→ ✅ No children

Node 20:
Range: (15, ∞)
20 > 15 ✅

20 < LONG_MAX ✅
→ ✅ No children

✅ All nodes pass ⇒ Final result: true (it is a valid BST)
*/
