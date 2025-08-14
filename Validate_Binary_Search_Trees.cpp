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
    bool isValidBST(TreeNode* root) {
        // Start the recursion with the full range of valid values for a BST.
        // Use LONG_MIN and LONG_MAX to avoid overflow issues for INT_MIN/INT_MAX edge cases.
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long min_val, long max_val) {
        // Base case: An empty tree is a valid BST.
        if (root == NULL) return true;

        // If the current node's value violates the min/max constraints, it's not a BST.
        if (root->val >= max_val || root->val <= min_val) {
            return false;
        }

        // Recursively check:
        // 1. Left subtree: values must be strictly less than root->val
        // 2. Right subtree: values must be strictly greater than root->val
        return isValidBST(root->left, min_val, root->val) &&
               isValidBST(root->right, root->val, max_val);
    }
};

/*
Time Complexity (TC): O(N)
- We visit each node exactly once.
- N = number of nodes in the tree.

Space Complexity (SC): O(H)
- H = height of the tree.
- This comes from the recursion stack depth.
- Worst case: O(N) for a skewed tree.
- Best case: O(log N) for a balanced tree.
*/
