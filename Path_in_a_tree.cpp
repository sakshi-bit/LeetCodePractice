#include <bits/stdc++.h> 
using namespace std;

/*   
    Definition for the binary tree node
*/
template <typename T = int>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left != NULL) {
            delete left;
        }
        if (right != NULL) {
            delete right;
        }
    }
};

// Recursive function to find the path from root to node with value x
bool getPath(TreeNode<int> *root, int x, vector<int>& ans) {
    if (root == NULL) {
        return false; // Base case: if node is NULL, return false
    }

    ans.push_back(root->data); // Add current node to path

    if (root->data == x) {
        return true; // Node found
    }

    // Recursively search in left or right subtree
    if (getPath(root->left, x, ans) || getPath(root->right, x, ans)) {
        return true;
    }

    // Backtrack if node not found in either subtree
    ans.pop_back();
    return false;
}

// Main function to return the path from root to node with value x
vector<int> pathInATree(TreeNode<int> *root, int x) {
    vector<int> ans;

    if (root == NULL) {
        return ans; // Tree is empty
    }

    getPath(root, x, ans); // Call helper function to populate ans
    return ans;
}

/*
Time Complexity: O(N)
- In the worst case, we visit all N nodes once to find the node with value x.

Space Complexity: O(H)
- H = height of the tree (due to recursion stack and path storage).
- In the worst case (skewed tree), H = N.
- In the best case (balanced tree), H = logN.
*/
