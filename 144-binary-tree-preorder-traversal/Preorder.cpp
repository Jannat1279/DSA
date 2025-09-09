class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder; // This will store the result of preorder traversal

        // If the tree is empty, return the empty result
        if (root == NULL)
            return preorder;

        stack<TreeNode*> s; // Stack to simulate the recursive call stack
        s.push(root);       // Start with the root node

        while (!s.empty()) {
            // Get the current node from the top of the stack
            root = s.top();
            s.pop();

            // Visit the node by adding its value to the result
            preorder.push_back(root->val);

            // Push right child first so that left is processed first (LIFO
            // order)
            if (root->right != NULL) {
                s.push(root->right);
            }

            // Push left child
            if (root->left != NULL) {
                s.push(root->left);
            }
        }

        return preorder; // Return the final preorder traversal
    }
};

/*
Example
        1
       / \
      2   3
     / \   \
    4   5   6

🔍 Step-by-Step Execution:
Initial state:
stack = [1]
preorder = []
Pop 1, push its children:
preorder = [1]
Push right (3), then left (2) → stack = [3, 2]

Pop 2, push its children:
preorder = [1, 2]
Push right (5), then left (4) → stack = [3, 5, 4]

Pop 4 (leaf node):
preorder = [1, 2, 4]
No children → stack = [3, 5]

Pop 5 (leaf node):
preorder = [1, 2, 4, 5]
No children → stack = [3]

Pop 3, push its right child (6):
preorder = [1, 2, 4, 5, 3]
Push right (6) → stack = [6]

Pop 6 (leaf node):
preorder = [1, 2, 4, 5, 3, 6]
No children → stack = []

✅ Final Output:
[1, 2, 4, 5, 3, 6]
*/
