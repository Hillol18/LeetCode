class Solution {
public:
    int help(TreeNode *h, int m){
        if(!h) return 0;

        int sum = help(h->left, max(m, h->val));
             sum += help(h->right, max(m, h->val));
        //cout<<m<<" "<<h->val<<" "<<(m < h->val)<<endl;
        return sum+(m <= h->val);


    }

    int goodNodes(TreeNode* root) {
        return help(root, INT_MIN);
    }
};
