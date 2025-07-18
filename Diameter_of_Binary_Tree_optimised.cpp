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
    // Recursive function to compute height of the tree
    // and update the diameter during the traversal
    int findHeight(TreeNode* root, int& diameter){
        if(root == NULL){
            return 0; // Base case: height of null node is 0
        }

        // Recursively find the height of left and right subtrees
        int lh = findHeight(root->left, diameter);
        int rh = findHeight(root->right, diameter);

        // Diameter at current node is left height + right height
        diameter = max(diameter, lh + rh);

        // Return height of current node
        return 1 + max(lh, rh);
    }

    // Main function to return the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; // Initialize diameter
        findHeight(root, diameter); // Compute diameter during height calculation
        return diameter; // Return the final diameter
    }
};

/*
Time Complexity: O(n)
 - Each node is visited once → O(n), where n is the number of nodes in the tree

Space Complexity: O(h)
 - h = height of the tree → recursion stack space
 - Worst case (skewed tree): O(n), Best case (balanced tree): O(log n)
*/
