/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If the tree is empty, no LCA exists
        if (root == NULL) {
            return NULL;
        }

        // Iteratively traverse the tree
        while (root != NULL) {
            // If both nodes are greater than current node, LCA lies in the right subtree
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            // If both nodes are smaller than current node, LCA lies in the left subtree
            else if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            // If one node is smaller and the other is larger (or equal), current node is the LCA
            else {
                return root;
            }
        }

        // If we reach here, no LCA was found
        return NULL;
    }
};

/*
Time Complexity (TC): O(H)
- H = height of the BST
- Best case (balanced tree): O(log N)
- Worst case (skewed tree): O(N)

Space Complexity (SC): O(1)
- Iterative approach uses no recursion stack.
*/
