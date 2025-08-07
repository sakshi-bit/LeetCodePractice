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

/*
Time Complexity: O(n) — Every node is visited at most twice.
Space Complexity: O(1) — No auxiliary stack or recursion used; modifies tree structure temporarily.
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;           // Stores the final inorder traversal
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // If no left child, visit the node and move to the right
                inorder.push_back(curr->val);
                curr = curr->right;
            } else {
                // Find the inorder predecessor (rightmost node of left subtree)
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    // Make a temporary thread from predecessor to current
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Thread already exists: restore original tree and visit current
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};
