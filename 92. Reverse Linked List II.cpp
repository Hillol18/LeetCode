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
class Solution {
public:

    ListNode* reverseList(ListNode* r){
        ListNode *pre = NULL,*n;

        while(r){
            //cout<<r->val<<endl;
            n = r->next;//store next;
            r->next = pre;//insert front
            pre = r;//replace previous
            r=n;//next cursor
        }

        return pre;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *n, *r = head, *l,*pre=NULL;
        int cnt=0;
        while(r){
            cnt++;

            if(cnt == left-1){
                pre = r;
            }
            if(cnt == left){
                l=r;
            }
            if(cnt == right){
                break;
            }
            r=r->next;
        }

        if(r){
            n = r->next;
            r->next = NULL;

            r = reverseList(l);
            if(left == 1){
                head = r;
            }
            if(pre) pre->next = r;

            while(r->next){
                //cout<<r->val<<endl;
                r=r->next;
            }
            r->next = n;

        }


        return head;

    }
};
