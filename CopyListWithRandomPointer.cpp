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

//Approach 1

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }

        unordered_map<Node*,Node*> mpp;

        Node* curr = head;
        Node* prev= NULL;
        Node* newHead = NULL;

        while(curr){

            Node *temp = new Node(curr->val);

            //store the deep copy address in the map with corresponding original address
            mpp[curr] = temp;

            if(newHead == NULL){
                newHead = temp;
                prev = newHead;
            }else{
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }

        //fill random pointers

        curr = head;
        Node * newCurr = newHead;

        while(curr){
            if(curr->random == NULL){
                newCurr->random = NULL;
            }else{
                newCurr->random = mpp[curr->random];
            }

            curr= curr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};
