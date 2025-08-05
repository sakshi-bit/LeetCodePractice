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
    // Helper function to compute height of leftmost path
    int findLeftHeight(TreeNode* root){
        int height = 0;
        while (root != NULL) {
            height++;
            root = root->left;
        }
        return height;
    }

    // Helper function to compute height of rightmost path
    int findRightHeight(TreeNode* root){
        int height = 0;
        while (root != NULL) {
            height++;
            root = root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int lh = findLeftHeight(root);  // Get height of leftmost path
        int rh = findRightHeight(root); // Get height of rightmost path

        // If left and right heights are equal, it's a perfect binary tree
        if (lh == rh) return (1 << lh) - 1; // 2^h - 1 nodes in perfect binary tree

        // Otherwise, recurse on left and right subtree
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

/**
 * Time Complexity:
 * - Worst Case: O(log^2 N)
 *   - Each level takes O(log N) time (for computing heights),
 *     and height of tree is O(log N) in complete binary tree.

 * Space Complexity:
 * - O(log N): Due to recursion stack in worst case for height-balanced tree.
 */
