/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if root is NULL or matches p or q, return root
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // Recursively search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If one side is NULL, return the other (could be potential LCA or NULL)
        if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        } else {
            // If both sides return non-null, root is the LCA
            return root;
        }
    }
};

/*
Time Complexity: O(N)
- We visit each node once in the worst case.

Space Complexity: O(H)
- H = height of the tree (due to recursion stack).
- Worst case: O(N) for skewed tree, Best case: O(logN) for balanced tree.
*/
