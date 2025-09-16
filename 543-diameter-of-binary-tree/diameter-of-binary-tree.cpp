class Solution {
public:
    // Function to compute the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;  // Variable to keep track of the maximum diameter found
        height(root, diameter);  // Compute height while updating diameter
        return diameter;  // Return the final diameter
    }

    // Helper function to compute height of the tree and update diameter
    int height(TreeNode* node, int& diameter) {
        // Base case: If the current node is NULL, return height as 0
        if (!node) return 0;

        // Recursively find the height of the left and right subtrees
        int left = height(node->left, diameter);
        int right = height(node->right, diameter);

        // Update the diameter. It could be the path passing through the current node
        // which is the sum of heights of left and right subtrees
        diameter = max(diameter, left + right);

        // Return the height of the current node which is
        // 1 (for the current node itself) + max height of left or right subtree
        return 1 + max(left, right);
    }
};

/*
Example:

        1
       / \
      2   3
     / \     
    4   5

🔁 Step-by-step Trace of the Function:
We'll use the helper function height() recursively to compute height and update diameter.

🔽 At Node 4:
Left and right children are NULL → height = 0
So, left = 0, right = 0, diameter = max(0, 0+0) = 0
Return height = 1 + max(0, 0) = 1

🔽 At Node 5:
Same as Node 4 → return height = 1, diameter still 0

🔼 Back at Node 2:
left = 1 (from Node 4), right = 1 (from Node 5)
diameter = max(0, 1+1) = 2
Return height = 1 + max(1, 1) = 2

🔽 At Node 3:
It's a leaf → height = 1, diameter still 2

🔼 Back at Node 1:
left = 2 (from Node 2), right = 1 (from Node 3)
diameter = max(2, 2+1) = 3
Return height = 1 + max(2, 1) = 3

✅ Final Output:
Diameter = 3

The longest path is: 4 → 2 → 1 → 3 (length = 3 edges)


*/
