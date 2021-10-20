class Solution {
public:
    
    void connectNode(Node* a, Node*b){
        a->next = b;
        b->prev = a;
    }
    
    
    void flat(Node* h, Node*& p){
        if(!h) return ;
        Node* next = h->next;
        Node* child = h->child;
        
        if(p){
            connectNode(p, h);
        }
        
        p = h;
        flat(child, p);
        flat(next, p);
        
        if(child) h->child = NULL;
    }
    
    Node* flatten(Node* head) {
        Node* pre = NULL;
        flat(head, pre);
        return head;
    }
};