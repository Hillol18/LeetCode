class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = NULL, *pre = NULL, *h=NULL;
        ListNode *ans = NULL;
        while(head){
            if(head->val < x){
                if(!ans){
                    ans = head;
                    left = head;

                }
                else{
                    left->next = head;
                    left = left->next;
                }

                if(pre){
                    pre->next = head->next;
                    head= pre;
                }
            }

            if(head->val >= x){
               if(!h) h = head;
               pre = head;
            }
            head = head->next;
        }
        if(left)
        left ->next = h;
        else ans = h;

        return ans;
    }
};
