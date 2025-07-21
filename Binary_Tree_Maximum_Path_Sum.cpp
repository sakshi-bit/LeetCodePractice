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

    // Helper function to compute max path sum from each node
    int findPathSum(TreeNode* root, int& pathsum) {
        if (root == NULL) {
            return 0; // Null node contributes 0 to the path sum
        }

        // Recursively compute the max path sums of left and right subtrees
        int lh = max(0, findPathSum(root->left, pathsum)); // Ignore negative contributions
        int rh = max(0, findPathSum(root->right, pathsum)); // Ignore negative contributions

        // Update global maximum path sum considering the current node
        pathsum = max(pathsum, root->val + lh + rh);

        // Return the max path sum including the current node and one subtree
        return max(lh, rh) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int pathsum = INT_MIN; // Initialize global maximum path sum
        findPathSum(root, pathsum); // Start post-order traversal from root

        // TC: O(N), where N is the number of nodes in the tree
        // SC: O(H), where H is the height of the tree (due to recursion stack)
        return pathsum;
    }
};
