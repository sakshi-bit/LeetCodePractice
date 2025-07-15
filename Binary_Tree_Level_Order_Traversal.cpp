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
     * @brief Performs level order traversal (BFS) of a binary tree.
     *
     * This function uses a queue to traverse the binary tree level-by-level
     * and collects the values of nodes at each level in a nested vector.
     *
     * @param root Pointer to the root node of the binary tree.
     * @return A vector of vectors, where each inner vector contains values from one level of the tree.
     *
     * Time Complexity: O(n), where n is the number of nodes in the binary tree.
     * Each node is visited exactly once.
     *
     * Space Complexity: O(n), for storing the output and the queue used for BFS.
     * In the worst case, the queue may hold up to n/2 nodes (for a complete binary tree).
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Enqueue left child if exists
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // Enqueue right child if exists
                if (node->right != nullptr) {
                    q.push(node->right);
                }

                level.push_back(node->val); // Add current node's value to the level
            }

            ans.push_back(level); // Add the level to the result
        }

        return ans;
    }
};
