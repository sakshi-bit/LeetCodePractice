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
    // Helper function to recursively build the tree
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx) {
        // Base case: no elements to construct the subtree
        if(start > end){
            return NULL;
        }

        // Current root value is the current element in preorder traversal
        int rootVal = preorder[idx];

        // Find rootVal in inorder to divide left and right subtrees
        int i = start;
        for(; i <= end; i++){
            if(rootVal == inorder[i]){
                break;
            }
        }

        // Move to next index in preorder
        idx++;

        // Create the root node
        TreeNode* root = new TreeNode(rootVal);

        // Recursively build left and right subtrees
        root->left = solve(preorder, inorder, start, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int idx = 0; // Index to track current root in preorder
        return solve(preorder, inorder, 0, size - 1, idx);
    }
};

/*
Time Complexity:
- O(n^2) in the worst case if the tree is skewed, because for each node we search for the root in the inorder array.
- Can be optimized to O(n) using a hashmap to store inorder value-to-index mapping.

Space Complexity:
- O(n) for recursion stack in worst case (skewed tree), and O(n) auxiliary space if using a hashmap.
*/
