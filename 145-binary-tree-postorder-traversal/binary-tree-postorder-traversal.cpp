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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;  // This will store the final postorder traversal

        // Edge case: if the tree is empty
        if (root == NULL) return postorder;

        stack<TreeNode*> s1;  // First stack: used for traversal
        stack<TreeNode*> s2;  // Second stack: used to reverse the order for postorder

        // Step 1: Push the root to the first stack
        s1.push(root);

        // Step 2: Traverse the tree in modified preorder (root → right → left)
        while (!s1.empty()) {
            TreeNode* node = s1.top();  // Get the current node
            s1.pop();

            // Push the node to the second stack
            s2.push(node);

            // Push left child first so it is processed after the right child
            if (node->left != NULL)
                s1.push(node->left);

            // Push right child next so it's processed before the left child
            if (node->right != NULL)
                s1.push(node->right);
        }

        // Step 3: Now s2 contains nodes in reverse postorder (root → right → left)
        // Pop from s2 to get the actual postorder (left → right → root)
        while (!s2.empty()) {
            postorder.push_back(s2.top()->val);  // Add the node value to result
            s2.pop();
        }

        return postorder;  // Return the final postorder traversal
    }
};
