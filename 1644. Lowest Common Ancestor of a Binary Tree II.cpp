/*

Hillol
*/

/**
 * Definition for a binary tree node.
 * };
 */
 #include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode *ans;
    TreeNode* help(TreeNode *r, TreeNode p, TreeNode q){
        if(!r) return NULL;

        //cout<<p->val<<" "<<q->val<<endl;
        TreeNode* left = help(r->left, *p, *q);
        TreeNode* right = help(r->right, *p, *q);


        if(left == p || right==p)  {p=r;}
        if(left == q || right == q) q=r;

        if(p==q && ans ==NULL) ans = p;

        if(r==p || r==q)return r;

        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = NULL;
        //p=pp;
        //q=qq;
        help(root, *p, *q);
        return ans;
    }
};
