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
    // Helper recursive function to perform right-first DFS
    void recursion(TreeNode* root, int level, vector<int>& ans) {
        if (root == NULL) {
            return; // Base case: empty node
        }

        // If this is the first node we're visiting at this level, add it to the answer
        if (ans.size() == level) {
            ans.push_back(root->val);
        }

        // Recurse on the right subtree first to ensure rightmost node is added first
        recursion(root->right, level + 1, ans);

        // Then recurse on the left subtree
        recursion(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans; // Empty tree
        }

        // Start recursion from root at level 0
        recursion(root, 0, ans);
        return ans;
    }
};

/*
 Time Complexity (TC): O(n)
   - Each node is visited once.

 Space Complexity (SC): O(h)
   - h = height of the tree (due to recursion stack)
   - Worst case: O(n) for skewed tree, O(log n) for balanced tree
*/
