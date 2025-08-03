/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // Helper function to mark parents of each node using BFS
    // SC: O(N) - storing parent pointers for all nodes
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_map){
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left != NULL) {
                parent_map[current->left] = current;
                q.push(current->left);
            }
            if (current->right != NULL) {
                parent_map[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        // Edge case: empty tree
        if (root == NULL) return ans;

        unordered_map<TreeNode*, TreeNode*> parent_map; // To store parent pointers
        markParents(root, parent_map); // Fill parent_map

        unordered_map<TreeNode*, bool> visited; // SC: O(N) to avoid revisiting nodes
        queue<TreeNode*> q;
        q.push(target); // Start BFS from target
        visited[target] = true;

        int current_level = 0;

        // BFS to go k levels away from target node
        // TC: O(N) in worst case - visiting all nodes
        while (!q.empty()) {
            int size = q.size();

            if (current_level++ == k) break;

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                // Traverse left child
                if (current->left != NULL && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }

                // Traverse right child
                if (current->right != NULL && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                // Traverse parent
                if (parent_map[current] && !visited[parent_map[current]]) {
                    q.push(parent_map[current]);
                    visited[parent_map[current]] = true;
                }
            }
        }

        // Collect all nodes at distance k
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }

        return ans;
    }
};
