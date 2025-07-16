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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)return new TreeNode(val);
        TreeNode* curr=root;
        while(true){
            if(curr->val<=val){
                // If the right is not empty, go to its right
                if(curr->right!=NULL)curr=curr->right;
                else{
                    // If NULL, create a new node and insert it
                    curr->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left!=NULL)curr=curr->left;
                else{
                    curr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

/*
Example
        20
       /  \
     10    30
     / \
    5  15

🔍 Insertion of 13 — Step-by-Step:
Initial root: 20
13 < 20 → go left to node 10

Node 10
13 > 10 → go right to node 15

Node 15
13 < 15 → go left, which is NULL → insert 13 here.

✅ Final BST after inserting 13:
markdown
Copy
Edit
        20
       /  \
     10    30
     / \
    5  15
       /
      13


*/
