/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *     right(right) {}
 * };
 */

class Solution {
public:
    int maxi = 0; // Stores the maximum diameter found so far

    // Helper function to calculate height of a subtree
    int findHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        // Height is 1 + max of left and right subtree heights
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }

    // Function to compute diameter of binary tree (O(n^2) approach)
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        // Calculate height of left and right subtrees
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        // Update maximum diameter if current diameter is greater
        maxi = max(maxi, lh + rh);

        // Recur for left and right subtrees to check for larger diameters
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        // Return the maximum diameter found
        return maxi;
    }
};

/*
Time Complexity: O(n^2)
 - For each node, we calculate height which takes O(n) time in worst case.
 - And we do this for every node → Total = O(n^2)

Space Complexity: O(h)
 - Where h is the height of the tree, due to recursion stack.
 - Worst case (skewed tree): O(n), Best case (balanced tree): O(log n)
*/
