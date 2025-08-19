/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* first;   // first misplaced node
    TreeNode* middle;  // middle node (used if swapped nodes are adjacent)
    TreeNode* last;    // second misplaced node (if not adjacent)
    TreeNode* prev;    // previous node in inorder traversal

    // Inorder traversal to detect misplaced nodes
    void inorder(TreeNode* root){
        if(root == NULL){
            return; // base case
        }

        // Traverse left subtree
        inorder(root->left);

        // Detect anomaly: if previous node > current node, it's misplaced
        if(prev != NULL && (prev->val > root->val)){
            if(first == NULL){
                // First anomaly -> record 'first' and 'middle'
                first = prev;
                middle = root;
            } else {
                // Second anomaly -> record 'last'
                last = root;
            }
        }

        // Update previous node pointer
        prev = root;

        // Traverse right subtree
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Initialize pointers
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN); // sentinel node

        // Perform inorder traversal to find swapped nodes
        inorder(root);

        // Case 1: non-adjacent swapped nodes -> swap first & last
        if(first && last){
            swap(first->val, last->val);
        }
        // Case 2: adjacent swapped nodes -> swap first & middle
        else if(first && middle){
            swap(first->val, middle->val);
        }
    }
};

/**
 * Time Complexity:
 * - Inorder traversal visits every node exactly once -> O(N),
 *   where N = number of nodes in the tree.
 *
 * Space Complexity:
 * - O(H) recursion stack space, where H = height of tree.
 * - Worst case (skewed tree): O(N).
 * - Best/average case (balanced tree): O(log N).
 */
