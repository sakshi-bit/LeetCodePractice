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
    // Helper function to find height of a subtree rooted at 'root'
    int findHeightTree(TreeNode* root){
        if(root == NULL){
            return 0;  // Base case: empty tree has height 0
        }
        int lh = findHeightTree(root->left);   // Height of left subtree
        int rh = findHeightTree(root->right);  // Height of right subtree
        return 1 + max(lh, rh);  // Height of current node = 1 + max of left and right subtree heights
    }

    // Function to check if tree is height-balanced
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;  // Base case: empty tree is balanced
        }

        // Get height of left and right subtrees
        int lh = findHeightTree(root->left);
        int rh = findHeightTree(root->right);

        // Check current node's balance condition
        if(abs(rh - lh) > 1) return false;

        // Recursively check left and right subtrees
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        // Return true only if both subtrees are balanced
        if(!left || !right) return false;
        return true;
    }
};
