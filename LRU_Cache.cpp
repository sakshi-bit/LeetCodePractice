class LRUCache {
public:
class node {
    public:
    int key;
    int val;
    node* next;
    node* prev;

    node(int _key,int _val){
        key=_key;
        val=_val;
    }
};
node* head = new node(-1,-1);
node* tail = new node(-1,-1);

int cap;
unordered_map<int, node*>mpp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(node* newNode){
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev= head;
        head->next=newNode;
        temp->prev=newNode;
    }

    void deleteNode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next= delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            node* node = mpp[key];
            int res = node->val;
            deleteNode(node);
            addNode(node);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            node* node = mpp[key];
            node->val = value;
            mpp.erase(key);
            deleteNode(node);
        }

        if(mpp.size()==cap){
            node* node =  tail->prev;
            mpp.erase( tail->prev->key);
            deleteNode(tail->prev);
        }
            node* newNode = new node(key,value);
            mpp[key]=newNode;
            addNode(newNode);
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
