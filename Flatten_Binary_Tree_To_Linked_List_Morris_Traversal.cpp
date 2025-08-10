/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 *
 * Time Complexity: O(n) 
 *    - Each node is visited once.
 *    - The inner while loop finding the rightmost node of the left subtree 
 *      still processes each edge only once overall.
 *
 * Space Complexity: O(1)
 *    - No additional data structures used, only pointers.
 */
class Solution {
public:
    void flatten(TreeNode* root, TreeNode*& curr) {
        while (curr != NULL) { // Iterate over nodes starting from root
            if (curr->left != NULL) { // If there is a left subtree
                TreeNode* prev = curr->left;
                
                // Find the rightmost node of the left subtree
                while (prev->right != NULL) {
                    prev = prev->right;
                }

                // Attach the original right subtree to the rightmost node of left subtree
                if (prev->right == NULL) {
                    prev->right = curr->right;
                    
                    // Move left subtree to right
                    curr->right = curr->left;
                    
                    // Clear left pointer to satisfy linked list property
                    curr->left = NULL;
                }
            }
            // Move to the next node (always on right after transformation)
            curr = curr->right;
        }
    }

    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        flatten(root, curr);
    }
};
