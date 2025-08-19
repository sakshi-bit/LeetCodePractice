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

/**
 * BSTIterator class
 * Helps us iterate BST either in ascending order (in-order)
 * or descending order (reverse in-order) using a stack.
 */
class BSTIterator {
private:
    stack<TreeNode*> mystack;  // stack to simulate recursion
    bool reverse = true;       // if true -> reverse in-order, if false -> normal in-order

    // Pushes all nodes along the path (left or right depending on reverse flag)
    void pushAll(TreeNode* node){
        while(node != NULL){
            mystack.push(node);
            if(reverse){
                // reverse in-order -> traverse right first
                node = node->right;
            } else {
                // normal in-order -> traverse left first
                node = node->left;
            }
        }
    }

public:
    // Constructor initializes iterator
    BSTIterator(TreeNode *root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    // Returns true if there are more nodes to iterate
    bool hasNext(){
        return !mystack.empty();
    }

    // Returns the next element in iteration
    int next(){
        TreeNode* tmpNode = mystack.top();
        mystack.pop();

        if(!reverse){
            // Normal in-order -> after visiting a node, go right
            pushAll(tmpNode->right);
        } else {
            // Reverse in-order -> after visiting a node, go left
            pushAll(tmpNode->left);
        }

        return tmpNode->val;
    }
};

/**
 * Solution class
 * Uses two BSTIterators:
 * - one for smallest (in-order traversal, left -> right)
 * - one for largest (reverse in-order traversal, right -> left)
 * Then applies two-pointer technique to find if there exists a pair with sum = k.
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        // Iterator l -> normal in-order (smallest first)
        BSTIterator l(root, false);

        // Iterator r -> reverse in-order (largest first)
        BSTIterator r(root, true);

        // Get initial values
        int i = l.next();  
        int j = r.next();

        // Two-pointer style search
        while(i < j){
            if(i + j == k){
                return true; // found pair
            } else if(i + j > k){
                // Sum too big -> move right iterator (decrease sum)
                j = r.next();
            } else {
                // Sum too small -> move left iterator (increase sum)
                i = l.next();
            }
        }
        return false; // no such pair found
    }
};

/**
 * Time Complexity:
 * - Each node is pushed & popped at most once into a stack.
 * - next() and hasNext() are O(1) amortized.
 * - findTarget() visits at most all nodes once => O(N), where N = number of nodes.
 *
 * Space Complexity:
 * - Stack stores at most O(H) nodes at any time (H = height of BST).
 * - In worst case (skewed tree), H = N, so O(N).
 * - For balanced BST, H ≈ logN.
 */
