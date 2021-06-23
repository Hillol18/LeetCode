/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
 |
 1 2 3 4 5 6 7
 1-null
 pre = 1 
 
 
*/

class Solution {
public:
    
    ListNode* reverse(ListNode *h){
        ListNode *pre = NULL;
        while(h){
            ListNode *n = h->next;
            h->next = pre;
            pre = h;
            h = n;
        }
        return pre;
    } 
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *h = head;
        
        ListNode *l_node = NULL, *ll = NULL;
        ListNode *r_node = NULL, *rr = NULL;
        int cnt = 0;
        while(h){
            cnt++;
            if(cnt < left) ll = h;
            
            if(cnt == left){
                l_node = h;
            }
            
            if(cnt == right){
                r_node = h;
            }
            
            h = h->next;
        }
        
        rr = r_node->next;
        
        r_node->next = NULL;
        h = reverse(l_node);
        /*ListNode *hh = h;
        while(hh){
            cout<<hh->val<<" ";
            hh = hh->next;
        }
        
        cout<<endl;
        */
        //cout<<h->val<<" "<<l_node->val<<endl;
        if(left == 1) {
            head = h;
        }
        else if(ll){ 
            ll->next = h;
        }
        
        if(l_node) l_node->next = rr;
        
        
        
        return head;
    }
};