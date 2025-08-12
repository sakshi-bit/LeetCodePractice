#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

// Function to count the number of nodes in the BST using Morris Traversal
int find_number_of_nodes(TreeNode<int>* root){
    int cnt = 0; // counts the nodes
    TreeNode<int>* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            cnt++; // visit the node
            curr = curr->right;
        } else {
            TreeNode<int>* prev = curr->left;
            // find inorder predecessor
            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                // create a temporary link to return to curr
                prev->right = curr;
                curr = curr->left;
            } else {
                // restore tree structure
                prev->right = NULL;
                cnt++; // visit the node
                curr = curr->right;
            }
        }
    }
    return cnt; // total number of nodes
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int cnt = 0; // counter for visited nodes in inorder
    if (root == NULL) {
        return 0; // empty tree
    }

    // count total nodes in the BST
    int n = find_number_of_nodes(root);
    int ans = -1; // stores the k-th largest value
    TreeNode<int>* curr = root;

    // standard Morris Inorder Traversal
    while (curr != NULL) {
        if (curr->left == NULL) {
            cnt++; 
            // n-k+1 is the position of k-th largest in inorder sequence
            if (cnt == n - k + 1) {
                ans = curr->data;
            }
            curr = curr->right;
        } else {
            TreeNode<int>* prev = curr->left;
            // find inorder predecessor
            while (prev->right != NULL && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                // create a temporary link to return to curr
                prev->right = curr;
                curr = curr->left;
            } else {
                // restore tree structure
                prev->right = NULL;
                cnt++;
                if (cnt == n - k + 1) {
                    ans = curr->data;
                }
                curr = curr->right;
            }
        }
    }
    return ans; // k-th largest element
}

// Time Complexity: O(N) 
// - Each edge is visited at most twice in Morris Traversal for both passes.
// - Counting nodes and finding k-th largest each take O(N), total is O(2N) ≈ O(N).
//
// Space Complexity: O(1) 
// - Morris Traversal uses constant extra space, no recursion or stack is used.
