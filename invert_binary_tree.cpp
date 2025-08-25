/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *       right(right) {}
 * };
 */

class Solution {
public:
    // Helper function to recursively invert the binary tree
    void invert(TreeNode* root){
        if(root == NULL){ 
            return; // base case: if node is null, do nothing
        }

        // First recursively invert the left subtree
        invert(root->left);

        // Then recursively invert the right subtree
        invert(root->right);

        // Swap left and right children of the current node
        TreeNode* tmp = root->left;   // store left child
        root->left = root->right;     // assign right to left
        root->right = tmp;            // assign old left to right
    }

    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;  // edge case: if tree is empty
        }

        // Call the recursive function to invert the tree
        invert(root);

        return root;  // return root of inverted tree
    }
};

/*
Time Complexity (TC): O(N) 
   - Each node is visited exactly once, and we perform O(1) work at each node.
   - N = number of nodes in the tree.

Space Complexity (SC): O(H) 
   - Recursive call stack depth is proportional to the height of the tree.
   - Worst case (skewed tree): O(N)
   - Best case (balanced tree): O(log N)
*/
