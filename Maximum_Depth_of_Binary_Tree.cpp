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
    int maxDepth(TreeNode* root) {
        // Base case: If root is null, tree is empty, so depth is 0
        if(root == NULL){
            return 0;
        }

        // Recursively find the depth of left and right subtrees
        int lh = maxDepth(root->left);  // left height
        int rh = maxDepth(root->right); // right height

        // Return the maximum of left and right subtree depth plus 1 (for current node)
        return 1 + max(lh, rh);
    }
};

/*
Time Complexity: O(n)
- We visit each node exactly once, so the time complexity is linear in the number of nodes.

Space Complexity: O(h)
- The maximum space used by the recursion stack is the height of the tree, i.e., O(h),
  where h is the height of the tree. In the worst case (skewed tree), this could be O(n).
*/
