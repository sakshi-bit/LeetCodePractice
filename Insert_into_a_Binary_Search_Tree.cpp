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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If tree is empty, new node becomes the root
        if(root == NULL){
            return new TreeNode(val);
        }

        TreeNode* current = root; // Pointer to traverse the tree

        while(true){
            // If value is less than or equal to current node's value, go left
            if(current->val >= val){
                if(current->left != NULL){
                    current = current->left; // Move to left child
                }else{
                    current->left = new TreeNode(val); // Insert at left leaf position
                    break;
                }
            }
            // If value is greater than current node's value, go right
            else{
                if(current->right != NULL){
                    current = current->right; // Move to right child
                }else{
                    current->right = new TreeNode(val); // Insert at right leaf position
                    break;
                }
            }
        }

        return root; // Return original root of the tree
    }
};

/*
Time Complexity: O(h) 
    - h = height of the BST
    - Worst case (skewed tree): O(n)
    - Best/average case (balanced tree): O(log n)

Space Complexity: O(1) 
    - No extra space used except pointers
*/
