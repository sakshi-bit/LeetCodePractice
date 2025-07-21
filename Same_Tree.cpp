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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If either of the nodes is null, return true only if both are null
        if (p == NULL || q == NULL) {
            return p == q;
        }

        // Check current node values and recursively check left and right subtrees
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    // TC: O(N), where N is the number of nodes in the smaller of the two trees
    // SC: O(H), where H is the height of the recursion stack (height of the tree)
};
