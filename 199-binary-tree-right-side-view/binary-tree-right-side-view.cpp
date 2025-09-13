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
        1
       / \
      2   3
       \    \
        5    4

Level 0
size = q.size() = 1
Loop i = 0:
Pop → node = 1, q = []
i == size - 1 → it's the last node of level → ans.push_back(1) → ans = [1]
Push children: left 2, right 3 → q = [2, 3]

Level 1
size = 2
Loop i = 0:
Pop → node = 2, q = [3]
i != size - 1 → don't record
Push children: left NULL, right 5 → q = [3, 5]
Loop i = 1:
Pop → node = 3, q = [5]
i == size - 1 → record → ans.push_back(3) → ans = [1, 3]
Push children: left NULL, right 4 → q = [5, 4]

Level 2
size = 2
Loop i = 0:
Pop → node = 5, q = [4]
i != size - 1 → don't record
5 has no children → q stays [4]
Loop i = 1:
Pop → node = 4, q = []
i == size - 1 → record → ans.push_back(4) → ans = [1, 3, 4]
4 has no children
*/
