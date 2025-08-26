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
    // Serialize the binary tree into a string representation
    // Using preorder traversal: root -> left -> right
    string serialize(TreeNode * root){
        if(root == NULL){
            return "N"; // N represents null nodes
        }
        // Example format: (1,(2,N,N),(3,N,N))
        return "(" + to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL || root == NULL){
            return false; // edge case: empty subRoot or root
        }
        
        // Serialize both trees
        string rootSerialized = serialize(root);
        string subRootSerialized = serialize(subRoot);

        // Check if serialized subRoot string exists inside serialized root string
        return rootSerialized.find(subRootSerialized) != string::npos;
    }
};

/**
 * Time Complexity (TC):
 * - serialize() visits each node once → O(N) for root tree, O(M) for subRoot tree
 * - total serialization → O(N + M)
 * - string find() in worst case → O(N * M)
 * - Overall worst-case TC: O(N * M), where N = number of nodes in root, M = number of nodes in subRoot
 *
 * Space Complexity (SC):
 * - Serialization stores each node as string → O(N + M)
 * - Recursive call stack for serialize() → O(H), where H = height of tree
 * - Overall SC: O(N + M + H)
 */
