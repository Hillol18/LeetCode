class Solution {
public:

    int ans = 0;

    int fun(TreeNode* root){

        if(!root)
            return 0;

       int x = fun(root->left);
       int y = fun(root->right);

        ans = max(ans, x+y);
        return 1+max(x,y);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        cout<<fun(root)<<endl;
        return ans;
    }
};
