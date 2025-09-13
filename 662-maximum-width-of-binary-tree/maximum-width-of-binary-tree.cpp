class Solution {
public:
    typedef unsigned long long ll;  // Use large type to avoid overflow when indexing

    // DFS traversal with position indexing
    void DFS(TreeNode* root, ll d, int level, vector<int>& arr, ll& maxWidth) {
        if(!root) 
            return;  // Base case: null node → stop

        // If this is the first node at this level, store its index
        if(level == arr.size()) {
            arr.push_back(d);
        } else {
            // Width = current_index - first_index_at_level + 1
            maxWidth = max(maxWidth, d - arr[level] + 1);
        }

        // Recurse left child with index 2*d+1
        DFS(root->left, 2*d + 1, level + 1, arr, maxWidth);

        // Recurse right child with index 2*d+2
        DFS(root->right, 2*d + 2, level + 1, arr, maxWidth);
    }

    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   
            return 0;  // Empty tree → width 0

        ll maxWidth = 1;    // Minimum width is 1 (root itself)
        vector<int> arr;    // arr[level] = first node's index at that level

        // Start DFS from root with index 0 at level 0
        DFS(root, 0, 0, arr, maxWidth);

        return maxWidth;
    }
};
