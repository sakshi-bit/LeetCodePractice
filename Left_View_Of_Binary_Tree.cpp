/* A binary tree node

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
    // Helper recursive function to capture the left view
    void recursion(Node* root, int level, vector<int>& ans){
        if(root == NULL){
            return; // Base case: If node is null, return
        }
        
        // If this is the first node at the current level, add it to the result
        if(ans.size() == level){
            ans.push_back(root->data); // Store the leftmost node at this level
        }

        // Recurse left first to prioritize leftmost nodes
        recursion(root->left, level + 1, ans);

        // Then recurse right
        recursion(root->right, level + 1, ans);
    }

    vector<int> leftView(Node *root) {
        vector<int> ans;

        if(root == NULL){
            return ans; // If tree is empty, return empty result
        }

        recursion(root, 0, ans); // Start recursion from root at level 0
        return ans;
    }
};

/*
Time Complexity (TC): O(N)
- Each node is visited exactly once.

Space Complexity (SC): O(H)
- H = height of the tree due to recursion stack.
- Worst case (skewed tree): O(N)
- Best case (balanced tree): O(log N)
*/
