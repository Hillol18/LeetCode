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

/*
|
3,9,10,8,20,15,7

10,9,8,3,15,20,7
       |
*/
class Solution {
public:
    
    TreeNode* dfs(int &idx, int l, int r, vector<int> &pre, vector<int> &in, unordered_map<int,int> &mp){
        if(l>r) return NULL;
        //cout<<idx<<" "<<l<<" "<<r<<endl;
        TreeNode *root = new TreeNode(pre[idx]);
        int i = mp[pre[idx]];
        idx++;
        root->left = dfs(idx, l, i-1, pre, in, mp);

        root->right = dfs(idx, i+1, r, pre, in, mp);
           
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = preorder.size();
        unordered_map<int, int>mp;
         
        for(int i = 0; i<n; i++){
            mp[inorder[i]] = i;
        }
        
        return dfs(idx, 0, n-1, preorder, inorder, mp);
    }
};