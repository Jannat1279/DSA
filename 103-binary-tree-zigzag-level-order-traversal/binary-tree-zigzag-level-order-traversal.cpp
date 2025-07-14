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

/*
Example
        1
       / \
      2   3
     / \   \
    4   5   6

🔁 Step-by-Step Execution:
Initialize:
queue = [1]
leftToRight = true

▶️ Level 0:
Size = 1
Spiral vector: [0]
Pop node 1 → insert at index 0
Enqueue: 2 and 3
Result: [[1]]
Flip direction → leftToRight = false

▶️ Level 1:
Queue = [2, 3]
Size = 2
Spiral vector: [0, 0]
Pop node 2 → insert at index 1 → spiral = [0, 2]
Enqueue: 4 and 5

Pop node 3 → insert at index 0 → spiral = [3, 2]
Enqueue: 6
Result: [[1], [3, 2]]
Flip direction → leftToRight = true

▶️ Level 2:
Queue = [4, 5, 6]
Size = 3
Spiral vector: [0, 0, 0]
Pop 4 → index 0 → [4, 0, 0]
Pop 5 → index 1 → [4, 5, 0]
Pop 6 → index 2 → [4, 5, 6]
Result: [[1], [3, 2], [4, 5, 6]]

✅ Final Output:
[
 [1],
 [3, 2],
 [4, 5, 6]
]
*/
