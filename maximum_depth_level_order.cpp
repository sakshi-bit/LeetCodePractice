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
    // Function to calculate the maximum depth of a binary tree using level-order traversal (BFS)
    int maxDepth(TreeNode* root) {
        int depth = 0;

        // If tree is empty, return depth as 0
        if (root == NULL) {
            return depth;
        }

        // Use a queue to perform BFS
        queue<TreeNode*> q;
        q.push(root);

        // Traverse level by level
        while (!q.empty()) {
            int size = q.size();  // Number of nodes at the current level

            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Push left child to the queue if it exists
                if (node->left != NULL) {
                    q.push(node->left);
                }

                // Push right child to the queue if it exists
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            // After processing one level, increment depth
            depth++;
        }

        return depth;
    }
};

/**
 * Time Complexity: O(n), where n is the number of nodes in the tree.
 * We visit each node exactly once in level-order traversal.
 *
 * Space Complexity: O(w), where w is the maximum width of the tree.
 * In the worst case, the queue stores all nodes at the last level.
 */
