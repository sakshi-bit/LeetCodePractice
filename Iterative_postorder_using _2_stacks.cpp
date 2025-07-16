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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;

        // Edge case: if the tree is empty
        if(root == NULL){
            return postorder;
        }

        // Two stacks are used to simulate post-order traversal
        stack<TreeNode*> st1;  // Used for processing nodes
        stack<TreeNode*> st2;  // Stores the nodes in reverse post-order

        st1.push(root);

        // First loop fills st2 with nodes in Root -> Right -> Left order
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);

            // Push left and right children of the node to st1
            if(root->left != NULL){
                st1.push(root->left);
            }
            if(root->right != NULL){
                st1.push(root->right);
            }
        }

        // Second loop extracts the nodes from st2 to get Left -> Right -> Root order
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};

/*
Time Complexity: O(N)
- Each node is pushed and popped from the stack exactly once.

Space Complexity: O(N)
- Two stacks are used, each can grow up to N in the worst case.
*/
