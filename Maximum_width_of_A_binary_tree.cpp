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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(root == NULL){
            return ans;
        }

        // Queue to store node along with its index
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            int mmin = it.second; // Minimum index at current level to prevent overflow
            int size = q.size();
            int first, last;

            for(int i = 0; i < size; i++){
                int curr_index = q.front().second - mmin; // Normalize index
                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0){
                    first = curr_index; // First index at level
                }
                if(i == size - 1){
                    last = curr_index; // Last index at level
                }

                if(node->left != NULL){
                    q.push({node->left, (long long)2 * curr_index + 1}); // Index for left child
                }
                if(node->right != NULL){
                    q.push({node->right, (long long)2 * curr_index + 2}); // Index for right child
                }
            }

            ans = max(ans, last - first + 1); // Width of current level
        }

        return ans;
    }
};

// Time Complexity: O(N), where N is the number of nodes in the binary tree.
// Space Complexity: O(N), due to the queue used for level order traversal.
