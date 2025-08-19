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
    TreeNode* middle;  // second misplaced node (if adjacent)
    TreeNode* last;    // second misplaced node (if non-adjacent)
    TreeNode* prev;    // previous node in inorder traversal

    // Morris inorder traversal to detect misplaced nodes
    void inorder(TreeNode* root) {
        TreeNode* current = root;
        while (current != NULL) {
            if (current->left == NULL) {
                // -------- visit current node --------
                if (prev != NULL && (prev->val > current->val)) {
                    if (first == NULL) {
                        // first anomaly detected
                        first = prev;
                        middle = current;
                    } else {
                        // second anomaly detected
                        last = current;
                    }
                }
                prev = current;
                current = current->right; // move right
            } else {
                // Find the inorder predecessor of current
                TreeNode* pre = current->left;
                while (pre->right != NULL && pre->right != current) {
                    pre = pre->right;
                }
                if (pre->right == NULL) {
                    // Make thread to return later
                    pre->right = current;
                    current = current->left;
                } else {
                    // Revert thread
                    pre->right = NULL;

                    // -------- visit current node --------
                    if (prev != NULL && (prev->val > current->val)) {
                        if (first == NULL) {
                            first = prev;
                            middle = current;
                        } else {
                            last = current;
                        }
                    }
                    prev = current;
                    current = current->right; // move right
                }
            }
        }
    }

public:
    void recoverTree(TreeNode* root) {
        if (root == NULL) return;

        // Initialize pointers
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN); // sentinel node

        // Perform Morris inorder traversal
        inorder(root);

        // Fix swapped nodes
        if (first && last) {
            swap(first->val, last->val);       // case: non-adjacent nodes swapped
        } else if (first && middle) {
            swap(first->val, middle->val);     // case: adjacent nodes swapped
        }
    }
};

/**
 * Time Complexity:
 * - Morris inorder traversal visits each node at most 2 times.
 * - O(N), where N = number of nodes in the BST.
 *
 * Space Complexity:
 * - O(1), since Morris Traversal does not use recursion or an explicit stack.
 * - Only a few pointer variables are used.
 */
