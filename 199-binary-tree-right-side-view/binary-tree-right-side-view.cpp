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
    void preOrder(TreeNode* root, int level, vector<int>& ans){
        if(root==NULL)return;
        // Main step
        if(ans.size()<=level)ans.push_back(root->val);
        // Recursive call
        preOrder(root->right, level+1, ans);
        preOrder(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preOrder(root,0,ans);
        return ans;
    }
};

/*
Example:
        1
       / \
      2   3
     /
    4

✅ Step-by-Step Calls:
📞 preOrder(1, 1, ans = [])
ans.size() = 0 < 1 → Add 1 → ans = [1]
Right child exists → Call preOrder(3, 2, ans)
Left child exists → Call preOrder(2, 2, ans) (after the right call)

📞 preOrder(3, 2, ans = [1])
ans.size() = 1 < 2 → Add 3 → ans = [1, 3]
Right child = NULL → no call
Left child = NULL → no call
(Return back to node 1, now call left child 2)

📞 preOrder(2, 2, ans = [1, 3])
ans.size() = 2 == 2 → Already visited level 2 → do nothing
Right child = NULL → no call
Left child exists → Call preOrder(4, 3, ans)

📞 preOrder(4, 3, ans = [1, 3])
ans.size() = 2 < 3 → Add 4 → ans = [1, 3, 4]
Right = NULL, Left = NULL → return

🔚 Final Output:
[1, 3, 4]

*/
