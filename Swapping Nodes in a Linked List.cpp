class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *first;
        ListNode *last = head;
        ListNode *ans = head;

        int cnt=0;
        while(head){
            cnt++;
            if(k==cnt){
                first = head;
            }

            if(cnt>k){
                last = last->next;
            }

            head = head->next;
        }

        if(first && last)
        swap(first->val, last->val);
        //cout<<first->val<<" "<<last->val<<endl;

        return ans;
    }
};
