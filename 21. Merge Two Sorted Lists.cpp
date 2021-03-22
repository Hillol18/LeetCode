class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* ans = NULL;
        ListNode* h = NULL;
        ListNode * cur;
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur=l1;
                l1= l1->next;
            }
            else {
                cur = l2;
                l2=l2->next;
            }

            if(!h){
                h=cur;
                ans=cur;
            }
            else{
                h->next =cur;
                h=h->next;
            }
        }

        while(l1){
            if(!h){
                h=l1;
                ans=l1;
            }
            else{
                h->next=l1;
                h=l1;

            }
            l1=l1->next;
        }

        while(l2){
            if(!h){
                h=l2;
                ans=l2;
            }
            else{
                h->next=l2;
                h=l2;

            }
            l2=l2->next;
        }

        return ans;
    }
};
