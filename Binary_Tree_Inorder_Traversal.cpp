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
    /**
     * @brief Recursive helper function to perform inorder traversal.
     *
     * This function visits the left subtree, processes the current node,
     * and then visits the right subtree in order to generate the inorder
     * sequence of the binary tree.
     *
     * @param root Pointer to the current TreeNode.
     * @param ans Reference to the vector storing the inorder traversal result.
     *
     * Time Complexity: O(n), where n is the number of nodes in the tree.
     * Space Complexity: O(n) for the recursion stack in the worst case (skewed tree) and O(n) for the result vector.
     */
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == nullptr) {
            return;
        }
        inorder(root->left, ans);          // Traverse left subtree
        ans.push_back(root->val);          // Visit node
        inorder(root->right, ans);         // Traverse right subtree
    }

    /**
     * @brief Returns the inorder traversal of a binary tree.
     *
     * @param root Pointer to the root node of the binary tree.
     * @return A vector containing the inorder traversal of the tree.
     *
     * Time Complexity: O(n), where n is the number of nodes in the tree.
     * Space Complexity: O(n), due to the recursion stack and result vector.
     */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};
