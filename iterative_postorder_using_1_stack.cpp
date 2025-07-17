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
    // Time Complexity: O(n) – Each node is visited once.
    // Space Complexity: O(n) – Stack can store up to n nodes in the worst case (skewed tree).
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) {
            return postorder; // Handle empty tree
        }

        TreeNode* curr = root;
        TreeNode* temp = NULL;
        stack<TreeNode*> st;

        while (!st.empty() || curr != NULL) {
            if (curr != NULL) {
                st.push(curr);         // Push current node to stack
                curr = curr->left;     // Move to left child
            } else {
                temp = st.top()->right; // Check right child of top node
                if (temp == NULL) {
                    // No right child, visit node
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);

                    // Keep popping while coming back from right subtree
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                } else {
                    // Move to right child
                    curr = temp;
                }
            }
        }

        return postorder;
    }
};
