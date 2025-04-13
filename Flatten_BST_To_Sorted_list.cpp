TC=  O(n^2) 

   Node *flattenBST(Node *root)
    {
        if(root == NULL){
            return NULL;
        }
        
        Node* head = flattenBST(root->left);
        root->left = NULL;
        
        root->right = flattenBST(root->right);
        
        if(head!=NULL){
            Node* temp = head;
            while(temp && temp->right){
                temp=temp->right;
            }
            temp->right=root;
        }else{
            head=root;
        }
        return head;
    }

TC= O(n)

class Solution
{
public:
    Node* prev = NULL;
    Node *flattenBST(Node *root)
    {
        if(root == NULL){
            return NULL;
        }
        
        Node* head = flattenBST(root->left);
        root->left=NULL;
        if(prev!=NULL){
            prev->right=root;
            prev=root;
        }else{
            prev=root;
        }
        
        root->right = flattenBST(root->right);
        if(head==NULL){
            return root;
        }
        return head;
    }
