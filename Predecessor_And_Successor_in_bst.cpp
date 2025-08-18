/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

// Function to find predecessor of given key in BST
int findPredecessor(TreeNode *root, int key){
    int predecessor = -1; // store predecessor value (default -1 if not found)
    while(root!=NULL){ // Traverse the tree | TC: O(h), SC: O(1)
        if(root->data < key){ 
            predecessor = root->data; // possible predecessor
            root=root->right;        // move right to find closer value
        }else{
            root=root->left;         // move left
        }
    }
    return predecessor; // returns largest value smaller than key
}

// Function to find successor of given key in BST
int findSuccessor(TreeNode *root, int key){
    int successor=-1; // store successor value (default -1 if not found)
    while(root!=NULL){ // Traverse the tree | TC: O(h), SC: O(1)
        if(key >= root->data){
            root=root->right;       // move right if current node <= key
        }else{
            successor=root->data;   // possible successor
            root=root->left;        // move left to find smaller valid successor
        }
    }
    return successor; // returns smallest value greater than key
}

// Wrapper function to return both predecessor and successor
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    pair<int,int>ans;
    // first = predecessor, second = successor
    ans.first = findPredecessor(root, key);   // O(h)
    ans.second = findSuccessor(root, key);    // O(h)
    return ans;
}

/*
Overall Complexity:
- Time Complexity: O(h) for each function call → O(h + h) = O(h), 
  where h = height of the BST. In balanced BST, h = log(n), in skewed BST, h = n.
- Space Complexity: O(1), since we only use variables (no recursion/extra DS).
*/
