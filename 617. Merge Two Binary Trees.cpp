class Solution {
public:
    void mergeTree(TreeNode* r1, TreeNode* r2){
        if(!r1 || !r2) return;
        
        mergeTree(r1->left, r2->left);
        mergeTree(r1->right, r2->right);
        
        r1->val += r2->val;
        
        if(!r1->left) r1->left = r2->left;
        if(!r1->right) r1->right = r2->right;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        mergeTree(root1, root2);
        
        return root1 ? root1 : root2;
    }
};