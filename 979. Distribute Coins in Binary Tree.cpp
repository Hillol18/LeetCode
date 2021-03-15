class Solution {
public:
     int help(TreeNode *r, int &ans){

        if(!r) return 0;

        int left = help(r->left, ans);
        int right= help(r->right, ans);

        //cout<<r->val<<" "left<<" "<<right<<endl;
        ans+= (abs(left) + abs(right));

        return r->val + left+right-1;
    }

    int distributeCoins(TreeNode* root) {
       int ans = 0;
        help(root, ans);
        return ans;
    }
};
