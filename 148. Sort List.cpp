/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
 
 1-2-3-4-6-7-8
 
 
 */
class Solution {
public:
    
    ListNode* split(ListNode* curr, int n){
        if(!curr) return NULL;
        ListNode *pre = curr;
        while(curr && n){
            n--;
            pre = curr;
            curr= curr->next;
        }
        
        pre->next = NULL;
        
        return curr;
        
    }
    
    ListNode* merge(ListNode *p1, ListNode *p2, ListNode* tail){
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;

        while(p1 && p2){
            if(p1->val < p2->val){
                curr->next = p1;
                p1 = p1->next;
            }
            else{
                curr->next = p2;
                p2 = p2->next;
            }
            
            curr = curr->next;
        }
        
        curr->next =  (p1 == NULL? p2: p1);
         
        while(curr->next){
            curr= curr->next;
        }
        curr->next = tail;
        
        return dummy->next;
    }
    
    void visit(ListNode* h){
        cout<<"visit ";
        while(h){
            cout<<h->val<<" ";
            h = h->next;
        }
        cout<<endl;
    }
    
    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode();
        int n = 0;
        while(curr){
            n++;
            curr = curr->next;
        }
        
        curr = head;
        
        ListNode * pre;
        for(int i = 1; i<=n; i = i<<1){
            pre = NULL;
            while(curr){
               ListNode *second = split(curr, i);
               ListNode *tail = split(second, i);
               ListNode *h = merge(curr, second, tail);
               
                if(!pre){
                    dummy->next = h;
                }
                else pre->next = h;
                
                curr = h;
                
                while(curr != tail){
                    pre = curr;
                    curr = curr->next;
                }   
            }
            curr = dummy->next;
        }
        return curr;
    }
};