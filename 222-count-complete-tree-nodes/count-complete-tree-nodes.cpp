class Solution {
public:
    // Helper: find height by going leftmost
    int findLeftHeight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }

    // Helper: find height by going rightmost
    int findRightHeight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;   // Empty tree → 0 nodes

        int lh = findLeftHeight(root);   // Height from leftmost path
        int rh = findRightHeight(root);  // Height from rightmost path

        // If left height == right height → it's a perfect binary tree
        // Nodes = 2^height - 1
        if(lh == rh) return (1 << lh) - 1;

        // Otherwise, count recursively (not a perfect subtree)
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
