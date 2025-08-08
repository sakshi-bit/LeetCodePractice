/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *     right(right) {}
 * };
 */

class Solution {
public:
    // Helper function to flatten the binary tree using reverse preorder traversal (right -> left -> root)
    void flatten_tree(TreeNode* node, TreeNode*& prev){
        // Base case: if the node is NULL, do nothing
        if(node == NULL){
            return;
        }

        // Recursively flatten the right subtree
        flatten_tree(node->right, prev);

        // Recursively flatten the left subtree
        flatten_tree(node->left, prev);

        // At this point, prev holds the previously processed node in preorder
        node->right = prev; // Point current node's right to prev
        node->left = NULL;  // Set left child to NULL
        prev = node;        // Move prev to current node
    }

    void flatten(TreeNode* root) {
        TreeNode* prev = NULL;

        // Start flattening from the root
        flatten_tree(root, prev);
    }
};

/*
Time Complexity: O(n) 
Each node is visited exactly once.

Space Complexity: O(h)
Due to recursion stack, where h is the height of the tree.
In worst case (skewed tree), h = n. In best case (balanced), h = log n.
*/
