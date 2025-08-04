/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to simulate spread of infection and return time taken
    int find_amount_of_time(TreeNode* target,
                            unordered_map<TreeNode*, TreeNode*>& parent_map) {
        int maxi = 0;  // Keeps track of time units
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        while (!q.empty()) {
            int fl = 0;  // Flag to check if any adjacent node is infected
            int size = q.size();  // Nodes to process in current time unit

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                // Infect left child if not already infected
                if (current->left != NULL && !visited[current->left]) {
                    fl = 1;
                    q.push(current->left);
                    visited[current->left] = true;
                }

                // Infect right child if not already infected
                if (current->right != NULL && !visited[current->right]) {
                    fl = 1;
                    q.push(current->right);
                    visited[current->right] = true;
                }

                // Infect parent if not already infected
                if (parent_map[current] && !visited[parent_map[current]]) {
                    fl = 1;
                    q.push(parent_map[current]);
                    visited[parent_map[current]] = true;
                }
            }

            // If at least one new node was infected, increment time
            if (fl) {
                maxi++;
            }
        }
        return maxi;
    }

    // Helper function to map parent nodes and find target node
    TreeNode* find_the_target(TreeNode* root, int start,
                              unordered_map<TreeNode*, TreeNode*>& parent_map) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target = NULL;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // If this is the node from where infection starts
            if (node->val == start) {
                target = node;
            }

            // Map parent for left child
            if (node->left != NULL) {
                parent_map[node->left] = node;
                q.push(node->left);
            }

            // Map parent for right child
            if (node->right != NULL) {
                parent_map[node->right] = node;
                q.push(node->right);
            }
        }
        return target;
    }

    // Main function
    int amountOfTime(TreeNode* root, int start) {
        if (root == NULL) {
            return 0;
        }

        unordered_map<TreeNode*, TreeNode*> parent_map;

        // Get the target node and build parent map
        TreeNode* target = find_the_target(root, start, parent_map);

        // Compute the amount of time taken to infect entire tree
        int ans = find_amount_of_time(target, parent_map);
        return ans;
    }
};

// Time Complexity:
// - find_the_target: O(N), where N is number of nodes (BFS traversal)
// - find_amount_of_time: O(N), worst case we visit each node once
// Total: O(N)

// Space Complexity:
// - parent_map and visited map: O(N)
// - queue for BFS: O(N)
// Total: O(N)
