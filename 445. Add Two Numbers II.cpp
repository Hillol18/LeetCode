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
            n=r->next;
            r->next=pre;
            pre = r;
            r=n;
        }

        return pre;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rl1 = reverseList(l1);
        ListNode *rl2 = reverseList(l2);
        ListNode *pre,*ans= NULL;
        int carry = 0;
        while(rl1 && rl2){
           // cout<<rl1->val<<" "<<rl2->val<<endl;
            if(!ans) ans=rl1;

            int sum = rl1->val + rl2->val +carry;

            carry = sum/10;
            rl1->val= sum%10;
            pre = rl1;
            rl1=rl1->next;
            rl2=rl2->next;

        }

        while(rl1 && carry){
            if(!ans) ans=rl1;
            int sum=(rl1->val +  carry);
            carry = sum/10;
            rl1->val = (sum)%10;
            pre = rl1;
            rl1=rl1->next;

        }

        if(rl2){
            if(!ans) ans=rl2;
            if(pre) pre->next = rl2;
        }




        while(rl2 && carry){
           int sum= rl2->val + carry;
            carry = sum/10;
            sum  = sum%10;

            rl2->val = sum;
            pre = rl2;
            rl2=rl2->next;
        }

        if(carry){
            pre->next = new ListNode(carry);

        }


        ans=reverseList(ans);
        return ans;

    }
};
