class Solution {
public:
    TreeNode *ans,*p,*q;
    TreeNode* help(TreeNode *r){
        if(!r) return NULL;

        //cout<<p->val<<" "<<q->val<<endl;
        TreeNode* left = help(r->left);
        TreeNode* right = help(r->right);


        if(left == p || right==p)  {p=r;}
        if(left == q || right == q) q=r;

        if(p==q && ans ==NULL) ans = p;

        if(r==p || r==q)return r;

        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* pp, TreeNode* qq) {
        ans = NULL;
        p=pp;
        q=qq;
        help(root);
        return ans;
    }
};
