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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ptr1 = head, *ptr2 = head;
        
        int cnt = 0;
        while(ptr2){
           
            if(cnt > n) ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            cnt++;
        }
        
        
        if(cnt == n) return ptr1->next;
        if(cnt > n) ptr1->next = ptr1->next->next;
        
        return head;
    }
};