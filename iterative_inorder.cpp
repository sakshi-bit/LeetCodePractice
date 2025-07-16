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
    vector<int> inorderTraversal(TreeNode* root) {
        // Stack to simulate recursive function call stack
        stack<TreeNode*> st;

        // Vector to store the in-order traversal result
        vector<int> inorder;

        // Start from root
        TreeNode* node = root;

        // Iterate until all nodes are traversed
        while (true) {
            if (node != NULL) {
                st.push(node);       // Go left as far as possible
                node = node->left;
            } else {
                if (st.empty()) {
                    break;           // If stack is empty, traversal is complete
                } else {
                    node = st.top(); // Backtrack and visit node
                    st.pop();
                    inorder.push_back(node->val); // Store node value
                    node = node->right;           // Visit right subtree
                }
            }
        }

        return inorder;
    }
};

/*
Time Complexity: O(N)
- Each node is visited exactly once.

Space Complexity: O(N)
- In worst case (completely unbalanced tree), stack can grow up to N.
- In best/average case (balanced tree), stack size is O(log N).
*/
