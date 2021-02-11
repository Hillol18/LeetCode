class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* h = head;
        if(!h) return h;

        Node *temp;
        while(h){
            temp = new Node(h->val);
            temp->random = NULL;
            temp->next = h->next;
            h->next = temp;
            h=temp->next;
        }

        h = head;
        while(h){
            if(h->random){
                h->next->random = h->random->next;
            }

            h=h->next->next;
        }

        h = head->next;
        Node *ans = h;
        while(h){
            cout<<h->val<<" "<<head->val<<endl;
            if(head->next && head->next->next){
                head->next = head->next->next;
            }
            else{
                head->next = NULL;
            }
            if(h->next && h->next->next){
                h->next = h->next->next;
            }
            else{
                break;
                h->next = NULL;
            }

            h = h->next;
            head = head->next;
        }
        return ans;
    }
};
