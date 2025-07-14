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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;         // Stack to keep track of nodes
        TreeNode* node = root;      // Start with the root node
        vector<int> inorder;        // Result vector to store inorder traversal

        // Continue looping until all nodes are processed
        while (true) {
            if (node != NULL) {
                // Go as far left as possible, pushing each node along the way
                s.push(node);       
                node = node->left;  // Move to left child
            } else {
                // If there's nothing left to the left and stack is empty, we're done
                if (s.empty()) break;

                // Backtrack: Pop the last node we visited
                node = s.top();    
                s.pop();

                // Visit the node (in inorder, after the left subtree)
                inorder.push_back(node->val);

                // Now move to the right subtree of the visited node
                node = node->right;
            }
        }

        return inorder;  // Return the full inorder traversal
    }
};
