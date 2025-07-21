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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        // If the tree is empty, return an empty result
        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> q; // For level order traversal
        q.push(root);

        bool flag = true; // Direction of traversal: true = left to right, false = right to left

        while (!q.empty()) {
            int size = q.size(); // Number of nodes at current level
            vector<int> level(size); // To store values of current level in zigzag order

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Determine index in level vector based on direction
                int index = (flag) ? i : (size - 1 - i);
                level[index] = node->val;

                // Push child nodes for next level
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            // Flip the direction for next level
            flag = !flag;

            // Add current level to the result
            ans.push_back(level);
        }

        return ans;

        // TC: O(N), where N is the total number of nodes in the tree
        // SC: O(N), for queue and result vector
    }
};
