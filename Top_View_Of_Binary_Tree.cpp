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
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // SC: O(N) for queue and map storage
        vector<int> ans;

        if (root == NULL) {
            // If the tree is empty, return an empty vector
            return ans;
        }

        // Queue stores pairs of (node, horizontal distance from root)
        queue<pair<Node*, int>> q;

        // Map to store the first node at every horizontal distance
        map<int, int> mpp;

        // Start with root at horizontal distance 0
        q.push({root, 0});

        // Level order traversal
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            // If this horizontal line is being seen for the first time
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;  // Store node data for that vertical level
            }

            // Add left child with horizontal distance -1
            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }

            // Add right child with horizontal distance +1
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        // Collect the result from the map, ordered by horizontal line
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        // TC: O(N * log N) due to map insertions and traversals
        //     where N is the number of nodes in the tree
        return ans;
    }
};
