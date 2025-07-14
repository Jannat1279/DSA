/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;  // Start from left to right

        while (!q.empty()) {
            int size = q.size();
            vector<int> spiral(size);  // To store nodes at current level in zigzag order

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Place node value at correct position based on direction
                int index = leftToRight ? i : (size - 1 - i);
                spiral[index] = node->val;

                // Push left and right children into the queue
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            ans.push_back(spiral);             // Add this level to answer
            leftToRight = !leftToRight;        // Flip direction for next level
        }

        return ans;
    }
};
