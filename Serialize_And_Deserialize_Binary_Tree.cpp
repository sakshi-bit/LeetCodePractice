/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return ""; // Empty tree case
        }

        string s = ""; // Result string
        queue<TreeNode*> q; // Queue for level order traversal
        q.push(root);

        // Level-order traversal
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                s.append("#,"); // Null marker
            } else {
                s.append(to_string(node->val) + ","); // Append value
                q.push(node->left);  // Push left child (even if NULL)
                q.push(node->right); // Push right child (even if NULL)
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL; // Empty string case
        }

        stringstream s(data); // To parse comma-separated values
        string str;

        // First value is root
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        // Reconstruct tree using level-order traversal
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            getline(s, str, ',');
            if (str == "#") {
                node->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Right child
            getline(s, str, ',');
            if (str == "#") {
                node->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

/*
Time Complexity:
- serialize(): O(N), where N is the number of nodes in the tree.
- deserialize(): O(N), since we process each node once.

Space Complexity:
- serialize(): O(N) for the queue and the output string.
- deserialize(): O(N) for the queue and tree reconstruction.
*/
