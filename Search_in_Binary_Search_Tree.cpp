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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Loop until we either find the node with the value or reach NULL
        while(root != NULL && root->val != val) {
            // If target value is smaller, go to left subtree
            // Else, go to right subtree
            root = val < root->val ? root->left : root->right;
        }
        // If found, root points to the node; else, it is NULL
        return root;
    }
};

/*
Time Complexity: O(h)
Where h is the height of the BST.
- Best case: O(log n) for balanced BST
- Worst case: O(n) for skewed BST

Space Complexity: O(1)
Iterative approach uses constant extra space.
*/
