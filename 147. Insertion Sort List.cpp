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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* curr = head;
        
        if(!head) return head;
        
        while(head){
            ListNode* prev = dummy;
            while(prev->next && prev->next->val < head->val){
                   prev = prev->next;               
            }
            
            ListNode* temp = prev->next;
            prev->next = head;
            
            head = head->next;
            prev->next->next = temp;
        }
        
        return dummy->next;
    }
};