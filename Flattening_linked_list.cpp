TC = O(M*N*N)
SC = O(N*M)
Aux Space = O(1)

 public:
    Node *mergeTwoList(Node* l1,Node* l2){
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        if(l1->data<=l2->data){
            l1->bottom = mergeTwoList(l1->bottom,l2);
            return l1;
        }else{
            l2->bottom = mergeTwoList(l1,l2->bottom);
            return l2;
        }
        return l1;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *head) {
        if(head == NULL){
            return NULL;
        }
        
        Node* head2 = flatten(head->next);
        
        return mergeTwoList(head,head2);
    }
