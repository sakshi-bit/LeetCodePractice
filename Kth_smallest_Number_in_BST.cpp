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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;      // counter for visited nodes
        int ans = -1;     // stores the k-th smallest value
        TreeNode* curr = root;
        
        while (curr != NULL) {
            if (curr->left == NULL) {
                // visiting node when no left child exists
                cnt++;
                if (cnt == k) {
                    ans = curr->val;
                }
                curr = curr->right;
            } else {
                // find inorder predecessor of curr
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    // create a temporary link to curr
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // restore tree structure
                    prev->right = NULL;
                    cnt++;
                    if (cnt == k) {
                        ans = curr->val;
                    }
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};

// Time Complexity: O(N) in the worst case, where N is the number of nodes, 
// because each edge is visited at most twice in Morris Traversal.
//
// Space Complexity: O(1) extra space, as Morris Traversal uses no stack or recursion.
