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
     * Recursive helper function to perform preorder traversal.
     * In preorder, we visit: Root ➝ Left ➝ Right
     * @param root: pointer to the current TreeNode
     * @param ans: vector to store the traversal result
     */
    void preorder(TreeNode* root, vector<int>& ans){
        // base case: if current node is null, return
        if(root == NULL){
            return;
        }

        // process current node
        ans.push_back(root->val);

        // recursively traverse left subtree
        preorder(root->left, ans);

        // recursively traverse right subtree
        preorder(root->right, ans);
    }

    /**
     * Main function to initiate preorder traversal.
     * @param root: pointer to the root of the binary tree
     * @return vector<int>: preorder traversal result
     */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

/**
 * Time Complexity: O(n)
 *  - We visit each node exactly once where n is the number of nodes in the binary tree.
 *
 * Space Complexity: O(n)
 *  - In the worst case (skewed tree), the recursion stack can go up to n.
 *  - Also, we use an extra vector of size n to store the result.
 */
