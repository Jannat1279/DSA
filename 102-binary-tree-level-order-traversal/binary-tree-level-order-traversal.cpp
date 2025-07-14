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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;  // Final result: vector of levels (each level is a vector of ints)

        // Edge case: if tree is empty, return empty result
        if (root == NULL) return ans;

        queue<TreeNode*> q;       // Queue for BFS traversal
        q.push(root);             // Start with the root node

        // Loop as long as there are nodes to process
        while (!q.empty()) {
            int size = q.size();        // Number of nodes at the current level
            vector<int> level;          // Temporary vector to store current level's values

            // Process all nodes at this level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();  // Get the front node from the queue
                q.pop();                     // Remove it from the queue

                // Add the node's value to the current level
                level.push_back(node->val);

                // Enqueue the left child if it exists
                if (node->left != NULL) {
                    q.push(node->left);
                }

                // Enqueue the right child if it exists
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            // After finishing the level, add it to the result
            ans.push_back(level);
        }

        return ans;  // Return the complete level order traversal
    }
};

/*
Example:
        1
       / \
      2   3
     /   / \
    4   5   6

🔍 Step-by-Step Execution:
Initial State:
queue = [1]
ans = []

Level 0:
size = 1
Process node 1
Add children: 2 and 3 to queue
level = [1]
ans = [[1]]

Level 1:
size = 2
Process node 2, add child 4
Process node 3, add children 5 and 6
level = [2, 3]
ans = [[1], [2, 3]]

Level 2:
size = 3
Process node 4 (no children)
Process node 5 (no children)
Process node 6 (no children)
level = [4, 5, 6]
ans = [[1], [2, 3], [4, 5, 6]]

✅ Final Output:
[[1], [2, 3], [4, 5, 6]]
*/
