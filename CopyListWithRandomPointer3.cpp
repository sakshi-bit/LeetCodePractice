/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    void InsertTheNodesInBetween(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            Node* copyNode = new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;

        }
    }
    void ConnectRandomPointers(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode = temp->next;
            if(temp->random!=NULL){
                copyNode->random=temp->random->next;
            }else{
                copyNode->random=NULL;
            }
            temp=temp->next->next;
        }
    }
    Node* ConnectTheNextPointer(Node* head){
        Node* nNode = new Node(-1);
        Node* res= nNode;
        Node* temp=head;
        while(temp!=NULL){
          res->next=temp->next;
          res=res->next;
          temp->next=temp->next->next;
          temp=temp->next;
        }
        return nNode->next;
    }
public:
    Node* copyRandomList(Node* head) {
        InsertTheNodesInBetween(head);
        ConnectRandomPointers(head);
        return ConnectTheNextPointer(head);
    }
};
