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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>preorder;

        // If the tree is empty, return an empty vector
        if(root == NULL){
            return preorder;
        }

        stack<TreeNode*> st;  // Stack to simulate recursion
        st.push(root);

        while(!st.empty()){
            root = st.top();   // Get the current node
            st.pop();

            // Preorder: root -> left -> right
            preorder.push_back(root->val);

            // Push right child first so left is processed first
            if(root->right != NULL){
                st.push(root->right);
            }

            if(root->left != NULL){
                st.push(root->left);
            }
        }

        return preorder;
    }
};
