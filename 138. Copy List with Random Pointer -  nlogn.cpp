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
public:

    map<Node *, Node *> mp;
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *r = head;
        while(r){
            mp[r] = new Node(r->val);
            r=r->next;
        }

        r= head;

        auto it = mp.begin();
        while(it != mp.end()){
             if(it->first->random){
                 it->second->random = mp[it->first->random];
             }

             if(it->first->next){
                 it->second->next = mp[it->first->next];
             }
            it++;
        }

       return mp[head];

    }
};
