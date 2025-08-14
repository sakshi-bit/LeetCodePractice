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
        // Base case: If root is NULL, there is no LCA.
        if (root == NULL) {
            return NULL;
        }

        int curr = root->val; // Current node value.

        // If both p and q are greater than current node, LCA lies in the right subtree.
        if (curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If both p and q are smaller than current node, LCA lies in the left subtree.
        if (curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If one of p or q is smaller and the other is greater, current node is the LCA.
        return root;
    }
};

/*
Time Complexity (TC): O(H)
- H = height of the tree.
- In a balanced BST, H = log N, so TC = O(log N).
- In the worst case (skewed tree), H = N, so TC = O(N).

Space Complexity (SC): O(H)
- Due to recursion stack depth.
- Best case (balanced BST): O(log N)
- Worst case (skewed tree): O(N)
*/
