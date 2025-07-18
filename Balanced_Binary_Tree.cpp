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
    // Helper function to check balance and return height
    int check(TreeNode* root){
        if(root == NULL){
            return 0; // Base case: height of null tree is 0
        }

        int lh = check(root->left); // Recursively get left subtree height
        if(lh == -1){               // If left subtree is unbalanced
            return -1;
        }

        int rh = check(root->right); // Recursively get right subtree height
        if(rh == -1){                // If right subtree is unbalanced
            return -1;
        }

        if(abs(lh - rh) > 1){        // If current node is unbalanced
            return -1;
        }

        return max(lh, rh) + 1;      // Return height of current subtree
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1; // If check returns -1, tree is not balanced
    }
};

/**
 * Time Complexity: O(n)
 *  - Each node is visited once, where n is the number of nodes in the tree.
 *
 * Space Complexity: O(h)
 *  - Due to recursion stack, where h is the height of the tree.
 *  - In worst case (skewed tree), SC = O(n); in best case (balanced tree), SC = O(log n)
 */
