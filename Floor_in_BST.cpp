#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X) {
    int floor = -1; // Stores largest value <= X; initialize to -1 if not found
    
    // Traverse the BST iteratively
    while (root) {
        if (root->val == X) {
            // Exact match found, this is the floor
            floor = root->val;
            return floor;
        }

        if (root->val > X) {
            // If current node value is greater than X, go left to find smaller values
            root = root->left;
        } else {
            // If current node value is less than or equal to X, update floor and go right
            floor = root->val;
            root = root->right;
        }
    }
    
    return floor; // Return the largest value <= X, or -1 if none found
}

/*
Time Complexity: O(h)
- h = height of BST
- Best case: O(log n) for balanced BST
- Worst case: O(n) for skewed BST

Space Complexity: O(1)
- Iterative approach uses constant extra space
*/
