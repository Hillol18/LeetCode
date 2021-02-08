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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    void failureFunc(ListNode * head, vector<pair<int,ListNode*>> &match){
        while(head){
            match.push_back(make_pair(0,head));
            head=head->next;
        }

        int j=1;
        int i=0;
        int n=match.size();
        while(j<n){
            //cout<<i<<" "<<j<<endl;
            if(match[j].second->val == match[i].second->val){
                match[j].first=++i;
                j++;
            }
            else if(i==0){
                j++;
            }
            else{
                i=match[i-1].first;
            }
        }
    }

    bool dfs(TreeNode* root, int index, vector<pair<int,ListNode*>> & match){

        if(index==match.size())
            return true;
        if(!root)
            return false;
        //cout<<root->val<<" "<<match[index].second->val<<" "<<index<<endl;
        while(index > 0 && match[index].second->val != root->val) index=match[index-1].first;

        if(index<0)
            index=0;
        if(root->val==match[index].second->val){
            if(dfs(root->left, index+1,match))
                return true;

            return dfs(root->right, index+1,match);
        }
        else{
            if(dfs(root->left,index,match)) return true;
            return dfs(root->right,index,match);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<pair<int, ListNode*>> match;
        failureFunc(head, match);

        return dfs(root,0,match);
    }
};
