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
    // Inorder traversal of BST to get sorted elements in 'store'
    void inorder(TreeNode* root, vector<int>& store) {
        if (root == NULL)
            return;
        inorder(root->left, store);  // Visit left subtree
        store.push_back(root->val);  // Store current node value
        inorder(root->right, store); // Visit right subtree
    }

    // Check if there exists a pair with sum equal to k
    bool findTarget(TreeNode* root, int k) {
        vector<int> store;
        inorder(root, store); // Step 1: Get sorted elements of BST

        // Step 2: Use two-pointer approach to find the target sum
        int start = 0;
        int end = store.size() - 1;

        while (start < end) {
            int temp = store[start] + store[end];

            if (temp == k) // Found the required pair
                return true;
            else if (temp < k) // Need a bigger sum → move start forward
                start++;
            else // Need a smaller sum → move end backward
                end--;
        }

        return false; // No such pair found
    }
};

/*
Example:
        5
       / \
      3   6
     / \    \
    2   4    7

Target sum k = 9
🔧 Step 1: Inorder Traversal
We perform an inorder traversal (left → root → right), which gives the sorted node values:

store = [2, 3, 4, 5, 6, 7]
🔧 Step 2: Two-Pointer Approach
Start = 0 → store[0] = 2
End = 5 → store[5] = 7
Check the sum:

🔁 First Iteration:
2 + 7 = 9 ✅
We found a pair!

✅ Final Output:
true
*/
