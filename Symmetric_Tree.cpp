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
    // Helper function to check mirror symmetry between two nodes.
    bool isSymmetricHelp(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right; // Return true if both are NULL, false if only one is.
        }

        if(left->val != right->val){
            return false; // If values don't match, not symmetric.
        }

        // Recursively check outer and inner pairs.
        return isSymmetricHelp(left->left, right->right) &&
               isSymmetricHelp(left->right, right->left);
    }

    // Main function to check if a tree is symmetric.
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetricHelp(root->left, root->right);
    }
};

/*
Time Complexity: O(n)
- Each node is visited once in the recursive check.

Space Complexity: O(h)
- Due to recursion stack. In worst case (skewed tree), h = n. In balanced tree, h = log(n).
*/
