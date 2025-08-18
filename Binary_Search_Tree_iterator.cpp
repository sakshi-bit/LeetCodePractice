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

class BSTIterator {
private:
    stack<TreeNode*> myStack; // stack to simulate inorder traversal

    // Helper function: pushes all left nodes into the stack
    void pushAll(TreeNode* node){
        // Keep traversing left subtree until NULL
        for(; node != NULL; myStack.push(node), node = node->left);
    }

public:
    // Constructor: initialize by pushing all left nodes from root
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    // @return the next smallest number in BST
    int next() {
        TreeNode* tmpNode = myStack.top(); // top = current smallest
        myStack.pop();                     // remove it
        pushAll(tmpNode->right);           // process right subtree
        return tmpNode->val;               // return smallest value
    }
    
    // @return whether we still have elements to process
    bool hasNext() {
        return !myStack.empty(); // true if stack not empty
    }
};

/**
 * Usage:
 * BSTIterator* obj = new BSTIterator(root);
 * int val = obj->next();
 * bool hasMore = obj->hasNext();
 */

/*
  Complexity Analysis:
- Time Complexity:
  • Constructor: O(h), where h = height of the tree (pushing left nodes).  
  • next(): Amortized O(1), since each node is pushed/popped exactly once.  
  • hasNext(): O(1).  

- Space Complexity:
  • O(h) for stack (at most height of tree stored at a time).  
  • In balanced BST, h = log(n); in skewed BST, h = n.  
*/
