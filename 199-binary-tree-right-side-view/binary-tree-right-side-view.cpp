class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                // If it's the last node of this level -> visible from right
                if(i == size - 1) ans.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        
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
