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

// Helper class to store info about a subtree
class NodeValue {
public:
    int maxNode;  // maximum value in this subtree
    int minNode;  // minimum value in this subtree
    int maxsize;  // size of largest BST in this subtree

    NodeValue(int maxNode, int minNode, int maxsize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxsize = maxsize;
    }
};

// Recursive helper that returns NodeValue for each subtree
NodeValue largestBSTSubtreeHelper(TreeNode* root){
    // Base case: An empty tree is a BST of size 0
    // min = +∞, max = -∞ ensures validity in comparisons
    if(root == NULL){
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

    // Postorder traversal: process left and right subtrees first
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // If current subtree is a BST:
    // left.maxNode < root->data < right.minNode
    if(left.maxNode < root->data && root->data < right.minNode){
        // Update min and max for current valid BST
        return NodeValue(
            max(root->data, right.maxNode),   // new max node
            min(root->data, left.minNode),    // new min node
            left.maxsize + right.maxsize + 1  // size of BST = L + R + root
        );
    } else {
        // If not BST, return invalid markers (+∞ and -∞)
        // and keep track of the largest BST seen in children
        return NodeValue(
            INT_MAX, INT_MIN,                 // invalidate range
            max(left.maxsize, right.maxsize)  // largest BST so far
        );
    }
}

// Main function to return size of largest BST in tree
int largestBST(TreeNode * root){
    return largestBSTSubtreeHelper(root).maxsize;
}

/*
-----------------------------------
 Complexity Analysis:
-----------------------------------
 Time Complexity: O(n)
- Each node is visited exactly once (postorder traversal).
- At each node, we do O(1) work (comparisons and min/max operations).
- So total = O(n), where n = number of nodes.

 Space Complexity: O(h)
- h = height of the tree.
- Space comes from recursion call stack.
- Worst case (skewed tree): O(n).
- Best case (balanced tree): O(log n).
*/
