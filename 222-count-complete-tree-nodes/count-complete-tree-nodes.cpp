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
    int findRightHeight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
    int findLeftHeight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=findLeftHeight(root);
        int rh=findRightHeight(root);
        if(lh==rh)return (1<<lh) - 1;

        return 1+ countNodes(root->left)+countNodes(root->right);
    }
};

/*
Example:
        1
       / \
      2   3
     /
    4

▶️ At Node 1:
findLeftHeight(1):
1 → 2 → 4 → NULL → lh = 3
findRightHeight(1):
1 → 3 → NULL → rh = 2
Since lh != rh, this is not a perfect binary tree.

Now we recursively count:
1 + countNodes(2) + countNodes(3)

▶️ At Node 2:
findLeftHeight(2) = 2 → 4 → NULL → lh = 2
findRightHeight(2) = 2 → NULL → rh = 1
Again, lh != rh, so:

1 + countNodes(4) + countNodes(NULL)
▶️ At Node 4:
findLeftHeight(4) = 1
findRightHeight(4) = 1
Now lh == rh, so:

return (1 << 1) - 1 = 1
So node 4 is counted using the shortcut.

▶️ At Node 3:
findLeftHeight(3) = 1
findRightHeight(3) = 1 → lh == rh

Return (1 << 1) - 1 = 1

🔢 Final Calculation:
Node 1:
→ 1 + count(2) + count(3)
→ 1 + (1 + 1 + 0) + 1
→ 1 + 2 + 1 = 4
✅ Final output = 4 nodes
(Tree nodes: 1, 2, 3, 4)
*/
