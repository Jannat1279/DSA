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
    // Global variable to store all valid paths
    vector<vector<int>> result;
    
    // Recursive helper function to explore all root-to-leaf paths
    void fill(TreeNode* root, int sum, vector<int> temp, int targetSum){
        // Base case: if node is NULL, just return
        if(!root) return;
        
        // Add current node's value to running sum
        sum += root->val;
        
        // Add current node's value to current path
        temp.push_back(root->val);
        
        // If it's a leaf node (no children)
        if(root->left == NULL && root->right == NULL){
            // Check if the path sum equals targetSum
            if(sum == targetSum){
                // Store this valid path
                result.push_back(temp);
            }
        }
        
        // Recursive call for left subtree
        fill(root->left, sum, temp, targetSum);
        
        // Recursive call for right subtree
        fill(root->right, sum, temp, targetSum);
    }
    
    // Main function called by user
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;             // running sum of current path
        vector<int> temp;        // temporary path storage
        fill(root, sum, temp, targetSum);
        return result;           // return all valid paths
    }
};
