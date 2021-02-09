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

    void gTree(TreeNode* r, int &sum){
        if(!r)
            return ;

        gTree(r->right, sum);
        sum+=r->val;
        r->val = sum;
        gTree(r->left, sum);

    }

    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        gTree(root, sum);
        return root;
    }
};
