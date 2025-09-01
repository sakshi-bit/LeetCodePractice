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
    // Helper function to count good nodes recursively
    int countGood(TreeNode* root, int maxSoFar) {
        if (!root) return 0; // Base case: null node contributes 0

        // If current node's value >= max value seen in path, it's a good node
        int count = (root->val >= maxSoFar) ? 1 : 0;

        // Update the max value along this path
        maxSoFar = std::max(maxSoFar, root->val);

        // Recurse to left and right subtrees
        count += countGood(root->left, maxSoFar);
        count += countGood(root->right, maxSoFar);

        return count; // Return total count for this subtree
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0; // Empty tree has 0 good nodes

        // Start recursion with root value as initial max
        return countGood(root, root->val);
    }
};

/*
Time Complexity (TC): O(N)
- Each node is visited exactly once in the tree.
- N = total number of nodes.

Space Complexity (SC): O(H)
- Recursive stack space due to DFS.
- H = height of the tree (O(logN) for balanced, O(N) for skewed tree).
*/
