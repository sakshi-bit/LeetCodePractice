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
    // Recursive function to build BST using preorder traversal
    TreeNode* build(vector<int>& preorder, int& i, int bound) {
        // Base case: if index is out of range OR current value > bound, return NULL
        if (i == preorder.size() || preorder[i] > bound) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i]); // create root from preorder
        i++; // move index forward

        // Left subtree: all nodes < root->val
        root->left = build(preorder, i, root->val);

        // Right subtree: all nodes > root->val but <= bound
        root->right = build(preorder, i, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};

/*
Time Complexity (TC): O(N)
- Each node is created and visited exactly once.
- No extra sorting or searching is needed.

Space Complexity (SC): O(H)
- H = height of BST (recursion stack).
- Worst case (skewed BST): O(N).
- Average case (balanced BST): O(log N).
*/
