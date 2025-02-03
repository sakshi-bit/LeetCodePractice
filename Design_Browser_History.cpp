class Node {
    public:
    string url;
    Node* prev;
    Node* next;

    Node(string _url): url(_url),prev(nullptr),next(nullptr){}
};
class BrowserHistory {
private:
Node* current;
public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        newNode->prev = current;
        current->next=newNode;
        current=newNode;
    }
    
    string back(int steps) {
        while(current->prev && steps>0){
            current=current->prev;
            steps--;
        }
        return current->url;
    }
    
    string forward(int steps) {
         while(current->next && steps>0){
            current=current->next;
            steps--;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
