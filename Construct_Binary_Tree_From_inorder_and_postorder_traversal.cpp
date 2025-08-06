/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *     right(right) {}
 * };
 */

class Solution {
public:
    // Recursive function to construct binary tree from inorder and postorder traversal
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart,
                    int inEnd, int postStart, int postEnd) {
        // Base case: if no elements are present to construct the subtree
        if (inStart > inEnd) {
            return NULL;
        }

        // The last element in postorder is the root of the current subtree
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of rootVal in inorder traversal
        int i = inStart;
        for (; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                break;
            }
        }

        // Calculate the number of nodes in the left and right subtrees
        int leftSize = i - inStart;
        int rightSize = inEnd - i;

        // Recursively build the left subtree
        root->left = solve(inorder, postorder, inStart, i - 1, postStart,
                           postStart + leftSize - 1);

        // Recursively build the right subtree
        root->right = solve(inorder, postorder, i + 1, inEnd,
                            postEnd - rightSize, postEnd - 1);

        return root;
    }

    // Main function to be called externally
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int inStart = 0;
        int inEnd = n - 1;
        int postStart = 0;
        int postEnd = n - 1;

        return solve(inorder, postorder, inStart, inEnd, postStart, postEnd);
    }
};

/*
Time Complexity: O(n^2)
- For each node, we perform a linear search in the inorder array to find the root index.
- This can be optimized to O(n) using a hashmap to store inorder indices.

Space Complexity: O(n)
- Due to recursive call stack in the worst case (skewed tree), the depth of the recursion is O(n).
- No additional space used apart from the recursion stack.
*/
