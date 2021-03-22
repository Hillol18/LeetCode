class Solution {
public:

    int help(TreeNode* root, int &ans){
        if(!root) return -100000000;

        int x = help(root->left, ans);
        int y = help(root->right, ans);
        //cout<<root->val<<" "<<x<<" "<<y<<endl;

        int ret = root->val;
        ans = max(ans, root->val);

        ans = max(ans, ret+x+y);


        ans = max(ans, ret + max(x,y));
        ans = max(ans,max(x,y));

        return max(ret, ret + max(x,y));

    }

    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        int x = help(root,ans);
        return ans;
    }
};
