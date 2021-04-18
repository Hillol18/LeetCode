class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *pre = NULL, *itr = NULL;
        ListNode *ans = head;

        while(head){
            cnt++;

            if(cnt>=n){
                if(pre) pre = pre->next;
                else if(itr){
                    pre = ans;
                }

                if(!itr){
                    itr = ans;
                }
                else itr = itr->next;

            }

            head = head->next;
        }

        if(pre && itr){
            pre->next = itr->next;
        }
        else if(itr){
            ans =  itr->next;
        }
        return ans;
    }
};
