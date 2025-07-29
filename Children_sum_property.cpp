// Trees.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <queue>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor initializes node with given value and sets children to NULL
    TreeNode(int value) {
        val = value;
        left = right = NULL;
    }
};

// Builds binary tree from user input in level-order
TreeNode* BuildTree() {
    int rootValue;
    cout << "Enter the root value (-1 for NULL)" << endl;
    cin >> rootValue;

    if (rootValue == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(rootValue);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* currNode = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter the left value (-1 for NULL)" << endl;
        cin >> leftVal;
        if (leftVal != -1) {
            currNode->left = new TreeNode(leftVal);
            q.push(currNode->left);
        }

        cout << "Enter the right value (-1 for NULL)" << endl;
        cin >> rightVal;
        if (rightVal != -1) {
            currNode->right = new TreeNode(rightVal);
            q.push(currNode->right);
        }
    }
    return root;
}

// Prints the binary tree in level-order traversal
void displayTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout << endl;
}

// Function to convert tree to a "Children Sum Tree"
// In a Children Sum Tree, every node's value becomes the sum of its children's values (if not a leaf)
void changeTree(TreeNode* root) {
    if (root == NULL) return;

    // Step 1: Calculate sum of child node values
    int child = 0;
    if (root->left != NULL) {
        child += root->left->val;
    }
    if (root->right != NULL) {
        child += root->right->val;
    }

    // Step 2: If child sum is greater, assign to root
    // else update children to match root value
    if (child >= root->val) {
        root->val = child;
    } else {
        if (root->left != NULL) {
            root->left->val = root->val;
        }
        if (root->right != NULL) {
            root->right->val = root->val;
        }
    }

    // Step 3: Recurse for children
    changeTree(root->left);
    changeTree(root->right);

    // Step 4: Postorder update of current node after child updates
    int tot = 0;
    if (root->left != NULL) {
        tot += root->left->val;
    }
    if (root->right != NULL) {
        tot += root->right->val;
    }

    if (root->left != NULL || root->right != NULL) {
        root->val = tot;
    }
}

/*
Time Complexity: O(N)
- We visit each node once during recursion and perform constant work at each step.

Space Complexity: O(H)
- Due to recursion stack, where H is the height of the tree (O(log N) for balanced, O(N) for skewed).
*/

int main() {
    TreeNode* root = BuildTree();     //  Build the tree from user input
    displayTree(root);                //  Print original tree
    changeTree(root);                //  Convert to Children Sum Tree
    displayTree(root);                //  Print modified tree
    return 0;
}
