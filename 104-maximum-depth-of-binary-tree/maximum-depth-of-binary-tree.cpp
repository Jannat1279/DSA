class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return 1+max(l,r);
    }
};

/*
Example:
     1
    / \
   2   3
  /
 4
maxDepth(4) = 1 (leaf node).
maxDepth(2) = 1 + max(1,0) = 2.
maxDepth(3) = 1.
maxDepth(1) = 1 + max(2,1) = 3.

So the maximum depth is 3.


maxDepth(1)
   |
   |---> maxDepth(2)   // left subtree of 1
   |        |
   |        |---> maxDepth(4)   // left subtree of 2
   |        |        |
   |        |        |---> maxDepth(NULL) = 0
   |        |        |---> maxDepth(NULL) = 0
   |        |        => return 1 + max(0,0) = 1
   |        |
   |        |---> maxDepth(NULL) = 0   // right subtree of 2
   |        => return 1 + max(1,0) = 2
   |
   |---> maxDepth(3)   // right subtree of 1
   |        |
   |        |---> maxDepth(NULL) = 0
   |        |---> maxDepth(NULL) = 0
   |        => return 1 + max(0,0) = 1
   |
   => return 1 + max(2,1) = 3

*/
