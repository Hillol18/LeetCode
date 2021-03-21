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

a a1 b b2
*/

class Solution {
public:

    map<Node *, Node *> mp;
    Node* copyRandomList(Node* head) {
        //cout<<"dd"<<endl;
        if(!head) return NULL;
        Node *r = head;
        while(r){

           Node *temp = new Node(r->val);

           Node *n = r->next;

           r->next = temp;
           temp->next = n;
            r=n;
        }


        r = head;
        while(r){
            if(r->random){
               r->next->random = r->random->next;
            }

          r= r->next->next;
        }


        Node* ans = head->next;
        r=head;
        Node *rr =head->next;
        //a-a1-b-b1-c-c1
        while(r){

            Node *nr = NULL;
            if(rr->next)
               nr=rr->next->next;

            r->next = r->next->next;
            rr->next = nr;

            rr=rr->next;
            r=r->next;
        }

       return ans;
    }
};
