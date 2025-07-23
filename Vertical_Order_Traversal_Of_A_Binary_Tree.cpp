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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        // Edge case: If the tree is empty, return empty result
        if (root == nullptr) {
            return ans;
        }

        // Map to store nodes by their (x, y) positions:
        // map<x-coordinate, map<y-coordinate, multiset of node values>>
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS: each element is {node, {x, y}}
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}}); // Root is at (0, 0)

        // BFS traversal
        while (!todo.empty()) {
            auto it = todo.front();
            todo.pop();

            TreeNode* node = it.first;
            int x = it.second.first;  // Horizontal distance
            int y = it.second.second; // Vertical level

            // Insert current node value into map at (x, y)
            nodes[x][y].insert(node->val);

            // Push left and right children with updated positions
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        // Collecting results from map
        for (auto& x_map : nodes) {
            vector<int> col;
            for (auto& y_map : x_map.second) {
                // Insert all values from the multiset into the column vector
                col.insert(col.end(), y_map.second.begin(), y_map.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

/*
 * Time Complexity: O(N * logN)
 * - Each node is inserted once: O(N)
 * - Insertion into multiset takes O(logK) where K is number of elements at a coordinate
 * - Final map traversal and insertions into vectors take O(N)
 * - Overall, due to map and multiset structures: O(N log N)

 * Space Complexity: O(N)
 * - Map and multiset store each node once: O(N)
 * - Queue stores at most N/2 nodes at a time: O(N)
 * - Final answer array: O(N)
 */
