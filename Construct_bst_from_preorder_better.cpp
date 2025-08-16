/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

 Time Complexity

Each node is processed exactly once.

Work per node = O(1).

Total = O(N)

Space Complexity

No extra data structures used.

Only recursion stack = O(H), where H is the height of the tree.

Worst case (skewed BST): O(N)

Average case (balanced BST): O(log N)
 * };
 */
class Solution {
public:
    // Recursive helper to build tree from preorder + inorder
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &idx,
                    int instart, int inend, unordered_map<int,int>& mpp) {
        if (instart > inend) { // base case: no subtree
            return NULL;
        }

        int rootval = preorder[idx];  // root comes from preorder
        idx++;                        // move preorder index forward

        int i = mpp[rootval];         // get root position in inorder (O(1) lookup)

        TreeNode* root = new TreeNode(rootval);   // create root node
        // build left subtree
        root->left = solve(preorder, inorder, idx, instart, i - 1, mpp);
        // build right subtree
        root->right = solve(preorder, inorder, idx, i + 1, inend, mpp);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;                 // copy preorder
        sort(inorder.begin(), inorder.end());           // inorder = sorted preorder
        int idx = 0;
        int n = inorder.size();
        
        unordered_map<int,int> mpp;                     // store inorder indices for O(1) access
        for (int i = 0; i < n; i++) {
            mpp[inorder[i]] = i;
        }

        return solve(preorder, inorder, idx, 0, n - 1, mpp);
    }
};
