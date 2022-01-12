class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans= head;
        while(head && head->next){
            swap(head->val, head->next->val);
            head = head->next->next;
        }
        return ans;
    }
};