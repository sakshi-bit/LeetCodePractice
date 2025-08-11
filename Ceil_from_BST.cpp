#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x) {
    int ceil = -1; // Stores the smallest value >= x, initialize to -1 if not found
    
    // Traverse the tree until node becomes NULL
    while (node != NULL) {
        if (x == node->data) {
            // If exact match is found, it's the ceil
            ceil = node->data;
            return ceil;
        }

        if (node->data < x) {
            // If current node's value is smaller, move right to find a larger value
            node = node->right;
        } else {
            // If current node's value is greater, update ceil and move left
            ceil = node->data;
            node = node->left;
        }
    }
    
    return ceil; // If no ceil exists, returns -1
}

/*
Time Complexity: O(h)
Where h is the height of the BST.
- Best case: O(log n) for balanced BST
- Worst case: O(n) for skewed BST

Space Complexity: O(1)
Iterative traversal uses constant extra space.
*/
