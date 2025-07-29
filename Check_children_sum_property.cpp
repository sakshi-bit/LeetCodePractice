/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        // Base case: if the node is NULL or a leaf node, it satisfies the sum property
        if(root == NULL || (root->left == NULL && root->right == NULL)) {
            return true;
        }

        // Calculate value of left child if it exists
        int leftVal = (root->left != NULL) ? root->left->data : 0;
        // Calculate value of right child if it exists
        int rightVal = (root->right != NULL) ? root->right->data : 0;

        // Check current node and recursively check left and right subtrees
        if(root->data == leftVal + rightVal &&
           isSumProperty(root->left) &&
           isSumProperty(root->right)) {
            return true;
        }

        return false;
    }
};

// Time Complexity: O(n), where n is the number of nodes in the binary tree
// Space Complexity: O(h), where h is the height of the binary tree (due to recursion stack)
