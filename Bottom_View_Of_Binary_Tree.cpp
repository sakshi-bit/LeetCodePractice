/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    // Function to return the bottom view of the binary tree
    vector<int> bottomView(Node *root) {
        vector<int> ans;

        // Edge case: if tree is empty, return empty vector
        if(root == NULL) {
            return ans;
        }

        // Map to store the last node at each horizontal distance (HD)
        // Key: HD, Value: Node's data
        map<int, int> mpp;

        // Queue for level order traversal. Pair stores node and its HD
        queue<pair<Node*, int>> q;

        q.push({root, 0});  // Root has HD = 0

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            // Overwrite every time so the last node at each HD is stored
            mpp[line] = node->data;

            // Left child has HD - 1
            if(node->left != NULL) {
                q.push({node->left, line - 1});
            }

            // Right child has HD + 1
            if(node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        // Traverse the map to get bottom view from left to right
        for(auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

/*
 Time Complexity (TC): O(N)
- Each node is visited once in level order traversal.

 Space Complexity (SC): O(N)
- Map stores at most N entries in the worst case.
- Queue can also hold up to N nodes.
*/
