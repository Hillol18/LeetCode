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

    struct cmp {
        bool operator()(ListNode *a, ListNode *b){
            return (a->val > b->val);
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        ListNode*ans = NULL, *r;

        for(int i=0;i<lists.size();i++){
            if(lists[i])
            pq.push(lists[i]);
        }


        while(!pq.empty()){
            ListNode * cur = pq.top();
            pq.pop();
            //cout<<cur->val<<endl;
            if(!ans){
                ans = cur;
                r=cur;
            }
            else{
                r->next = cur;
                r=r->next;
            }


            cur = cur->next;
            if(cur){
                pq.push(cur);
            }
        }



        return ans;

    }
};
