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
    int getDecimalValue(ListNode* head) {
        int cnt = 0;
        ListNode *h = head;
        
        while(h){
            cnt++;
            h = h->next;
        }
        int number = 0;
        cnt--;
        while(cnt >= 0){
            if(head -> val == 1){
                number |= (1<<cnt);
            }
            head = head->next;
            cnt--;
        }
        return number;
    }
};