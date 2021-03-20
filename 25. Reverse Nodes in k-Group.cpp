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


ListNode* reverseList(ListNode *head){
        ListNode *pre= NULL;
        ListNode *cur=head,*n;
        int cnt=4;
        ListNode *ans = NULL;
        while(cur){
            n = cur->next;
            cur->next =pre;
            pre = cur;
            cur = n;
        }

        return pre;
}

ListNode* nextKthcell(ListNode *r, int k){

    while(r){
        k--;
        if(k==0)
            return r;
        r=r->next;
    }
    return NULL;
}

class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *pre = NULL, *ans = NULL;
        while(head){
           ListNode * cur =  nextKthcell(head,k);

            if(!cur)  break;

            ListNode *n = cur->next;
            cur->next =NULL;
            ListNode *r = reverseList(head);

            if(pre) pre->next = r;
            if(ans==NULL)
            {
               ans = r;
            }

            while(r->next) {
                //cout<<r->val<<endl;
                r=r->next;

            };
            pre = r;
            r->next = n;

            head = n;
        }
        return ans == NULL ? head : ans;
    }
};
