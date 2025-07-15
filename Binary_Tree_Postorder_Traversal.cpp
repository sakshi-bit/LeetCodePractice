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
     * @brief Recursive helper function to perform postorder traversal.
     *
     * Postorder traversal visits the left subtree, then the right subtree,
     * and finally the current node. This function stores the result in `ans`.
     *
     * @param root Pointer to the current TreeNode.
     * @param ans Reference to the vector storing the traversal result.
     *
     * Time Complexity: O(n), where n is the number of nodes in the binary tree.
     * Space Complexity: O(n), due to recursion stack in worst-case (skewed tree)
     * and storage in result vector.
     */
    void postorder(TreeNode* root, vector<int>& ans){
        if (root == nullptr) {
            return;
        }
        postorder(root->left, ans);   // Traverse left subtree
        postorder(root->right, ans);  // Traverse right subtree
        ans.push_back(root->val);     // Visit node
    }

    /**
     * @brief Returns the postorder traversal of a binary tree.
     *
     * Calls the helper function to fill the result vector.
     *
     * @param root Pointer to the root node of the binary tree.
     * @return Vector containing postorder traversal of the tree.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};
