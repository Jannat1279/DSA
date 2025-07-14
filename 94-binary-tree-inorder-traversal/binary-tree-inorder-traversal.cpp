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

/*
Example:
        4
       / \
      2   5
     / \
    1   3

| Step | Current Node   | Stack      | Inorder Vector   | Action                           |
| ---- | -------------- | ---------- | ---------------- | -------------------------------- |
| 1    | 4              |  []        |  []              | Push 4, go to left               |
| 2    | 2              |  [4]       |  []              | Push 2, go to left               |
| 3    | 1              |  [4, 2]    |  []              | Push 1, go to left               |
| 4    | NULL           |  [4, 2, 1] |  []              | node is NULL, pop and visit 1    |
| 5    | 1.right (NULL) |  [4, 2]    |  [1]             | Right is NULL → pop and visit 2  |
| 6    | 2.right (3)    |  [4]       |  [1, 2]          | Move to right child 3            |
| 7    | 3              |  [4]       |  [1, 2]          | Push 3, go to left (NULL)        |
| 8    | NULL           |  [4, 3]    |  [1, 2]          | node is NULL, pop and visit 3    |
| 9    | 3.right(NULL)  |  [4]       |  [1, 2, 3]       | Right is NULL → pop and visit 4  |
| 10   | 4.right (5)    |  []        |  [1, 2, 3, 4]    | Move to right child 5            |
| 11   | 5              |  []        |  [1, 2, 3, 4]    | Push 5, go left (NULL)           |
| 12   | NULL           |  [5]       |  [1, 2, 3, 4]    | Pop and visit 5                  |
| 13   | 5.right(NULL)  |  []        |  [1, 2, 3, 4, 5] | Stack empty and node NULL → DONE |

*/
