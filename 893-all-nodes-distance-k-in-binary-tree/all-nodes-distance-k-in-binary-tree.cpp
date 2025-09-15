class Solution {
public:
    // Step 1: Build parent mapping
    void buildParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent; // child -> parent
        buildParent(root, parent);

        // Step 2: BFS from target
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);

        int dist = 0;

        while(!q.empty()) {
            int size = q.size();
            if(dist == k) break; // stop at level k

            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front(); q.pop();

                // neighbors: left, right, parent
                if(curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if(curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                if(parent.count(curr) && !visited.count(parent[curr])) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
            dist++;
        }

        // Step 3: collect all nodes at distance k
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
