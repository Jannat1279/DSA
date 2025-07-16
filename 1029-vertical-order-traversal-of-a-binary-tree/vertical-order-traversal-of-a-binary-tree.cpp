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
    // Recursive helper function to perform preorder traversal.
    // Parameters:
    // node     -> current TreeNode
    // vertical -> horizontal distance from the root (left = -1, right = +1)
    // level    -> depth (top to bottom = increasing level)
    // nodes    -> nested map to store node values by vertical and level
    void preorder(TreeNode* node, int vertical, int level,
                  map<int, map<int, multiset<int>>>& nodes) {
        if (node == nullptr)
            return; // Base case: null node, do nothing

        // Insert the current node value into the corresponding vertical and
        // level
        nodes[vertical][level].insert(node->val);

        // Recur for the left subtree (vertical - 1, level + 1)
        preorder(node->left, vertical - 1, level + 1, nodes);

        // Recur for the right subtree (vertical + 1, level + 1)
        preorder(node->right, vertical + 1, level + 1, nodes);
    }

    // Function to return the vertical order traversal of the binary tree
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Nested map:
        // 1st key: vertical index
        // 2nd key: level (depth)
        // multiset: to maintain sorted order of node values at the same
        // position
        map<int, map<int, multiset<int>>> nodes;

        // Fill the map using preorder traversal
        preorder(root, 0, 0, nodes);

        // Prepare the final answer
        vector<vector<int>> ans;

        // Traverse the vertical map in left-to-right order
        for (auto& p : nodes) {
            vector<int> col;

            // Traverse each level in top-down order
            for (auto& q : p.second) {
                // Add all node values (already sorted via multiset) into the
                // current column
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            // Append the column to the final answer
            ans.push_back(col);
        }

        return ans;
    }
};
