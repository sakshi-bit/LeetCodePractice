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
class Solution {
public:
    // Helper function to find the rightmost node in a subtree
    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL){ // if no right child, this is the last right
            return root;
        }
        return findLastRight(root->right); // keep moving right
    }

    // Helper function to handle deletion of a node
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL){ // if no left child, return right child
            return root->right;
        }
        if(root->right==NULL){ // if no right child, return left child
            return root->left;
        }
        // both children exist
        TreeNode* rightChild = root->right; // store right subtree
        TreeNode* lastRightChild = findLastRight(root->left); // find rightmost node of left subtree
        lastRightChild->right = rightChild; // attach right subtree to the rightmost node of left subtree
        return root->left; // new root for this subtree will be left child
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){ // if tree is empty
            return NULL;
        }
        if(root->val == key){ // if root is the node to delete
            return helper(root);
        }

        TreeNode* dummy = root; // store original root to return later
        while(root!=NULL){
            if(root->val > key){ // search in left subtree
                if(root->left!=NULL && root->left->val == key){ // found node to delete
                    root->left = helper(root->left);
                    break;
                }else{
                    root = root->left; // move left
                }
            }else{ // search in right subtree
                if(root->right!=NULL && root->right->val == key){ // found node to delete
                    root->right = helper(root->right);
                    break;
                }else{
                    root = root->right; // move right
                }
            }
        }
        return dummy; // return original root
    }
};

/*
Time Complexity: O(H) where H is the height of the tree 
- In worst case, H = N for skewed trees, so O(N)
- For balanced trees, H = logN

Space Complexity: O(1)
- Only uses a few pointers, no extra recursion stack (iterative search)
*/
