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

// Time Complexity: O(n)
// Each node is visited at most twice (once to create the thread, once to remove it)

// Space Complexity: O(1)
// No stack or recursion used, Morris traversal modifies the tree temporarily


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder; // Stores the result of preorder traversal
        TreeNode* curr = root;

        // Morris Traversal: Iterative, constant space preorder traversal
        while (curr != NULL) {
            // Case 1: If no left child, process current node and move to right child
            if (curr->left == NULL) {
                preorder.push_back(curr->val); // Visit the node
                curr = curr->right;
            } else {
                // Find the inorder predecessor of current node
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                // Case 2: Create a thread and move to left subtree
                if (prev->right == NULL) {
                    preorder.push_back(curr->val); // Visit the node before threading (preorder)
                    prev->right = curr;            // Create temporary thread to current
                    curr = curr->left;
                }
                // Case 3: Thread already exists, remove it and move to right subtree
                else {
                    prev->right = NULL; // Remove the temporary thread
                    curr = curr->right;
                }
            }
        }

        return preorder;
    }
};
