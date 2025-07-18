/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

vector<vector<int>> getTreeTraversal(TreeNode *root) {
    vector<vector<int>> ans;

    // Edge case: if tree is empty, return empty result
    if (root == NULL) {
        return ans;
    }

    vector<int> pre;  // Stores preorder traversal
    vector<int> post; // Stores postorder traversal
    vector<int> inn;  // Stores inorder traversal

    // Stack to simulate recursion. Pair<TreeNode*, int> where int denotes traversal state:
    // 1 = Preorder, 2 = Inorder, 3 = Postorder
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // --- Preorder (Node -> Left -> Right) ---
        if (it.second == 1) {
            pre.push_back(it.first->data); // Process node for preorder
            it.second++;                   // Move to next stage (Inorder)
            st.push(it);                   // Push back with updated state
            if (it.first->left != NULL) {
                st.push({it.first->left, 1}); // Push left child
            }

        // --- Inorder (Left -> Node -> Right) ---
        } else if (it.second == 2) {
            inn.push_back(it.first->data); // Process node for inorder
            it.second++;                   // Move to next stage (Postorder)
            st.push(it);                   // Push back with updated state
            if (it.first->right != NULL) {
                st.push({it.first->right, 1}); // Push right child
            }

        // --- Postorder (Left -> Right -> Node) ---
        } else {
            post.push_back(it.first->data); // Final process for postorder
        }
    }

    // Order of insertion as per requirement: inorder, preorder, postorder
    ans.push_back(inn);
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}

/*
Time Complexity: O(N)
- Every node is visited exactly 3 times (preorder, inorder, postorder logic).
- Hence overall time is linear in the number of nodes.

Space Complexity: O(N)
- Stack space in worst case is O(N) for skewed trees.
- Additional O(N) space for storing each traversal.
*/
