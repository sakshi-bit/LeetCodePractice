/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Helper function to check if a node is a leaf node
    bool isLeafNode(Node *root){
        return (root->left == NULL && root->right == NULL);
    }

    // Adds all the non-leaf left boundary nodes (top-down)
    void addLeftNodes(Node *root, vector<int>& ans){
        Node* curr = root->left;
        while(curr != NULL){
            if(!isLeafNode(curr)){
                ans.push_back(curr->data);
            }
            // Move to the next left boundary node
            if(curr->left != NULL){
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    // Adds all the leaf nodes using DFS (in left-to-right order)
    void addLeafNodes(Node *root, vector<int>& ans){
        if(isLeafNode(root)){
            ans.push_back(root->data);
            return;
        }
        if(root->left != NULL){
            addLeafNodes(root->left, ans);
        }
        if(root->right != NULL){
            addLeafNodes(root->right, ans);
        }
    }

    // Adds all the non-leaf right boundary nodes (bottom-up)
    void addRightNodes(Node *root, vector<int>& ans){
        Node* curr = root->right;
        vector<int> temp; // Temporary to store right boundary in reverse

        while(curr != NULL){
            if(!isLeafNode(curr)){
                temp.push_back(curr->data);
            }
            // Move to the next right boundary node
            if(curr->right != NULL){
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }

        // Add the right boundary in reverse order to the final result
        for(int i = temp.size() - 1; i >= 0; i--){
            ans.push_back(temp[i]);
        }
    }

    // Main function to perform boundary traversal in anti-clockwise order
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;

        if(root == NULL){
            return ans;
        }

        // Add root only if it's not a leaf node
        if(!isLeafNode(root)){
            ans.push_back(root->data);
        }

        // Add left boundary nodes (excluding leaves)
        addLeftNodes(root, ans);

        // Add all leaf nodes (from left to right)
        addLeafNodes(root, ans);

        // Add right boundary nodes (excluding leaves, in reverse)
        addRightNodes(root, ans);

        return ans;
    }
};

/*
Time Complexity: O(n)
 - Every node is visited exactly once:
    → O(h) for left boundary (excluding leaves)
    → O(n) for all leaf nodes
    → O(h) for right boundary (excluding leaves)
 - Total = O(n), where n is the number of nodes

Space Complexity: O(h)
 - Due to recursion stack in addLeafNodes (DFS), where h = height of tree
 - Temporary vector for right boundary stores up to O(h) nodes
 - Overall auxiliary space = O(h)
*/
