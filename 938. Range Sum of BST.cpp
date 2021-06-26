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
    
    int dfs(TreeNode *root, int low, int high){
        if(!root) return 0;
        if(root->val < low)
            return dfs(root->right, low, high);
        if(root->val > high) 
            return dfs(root->left, low, high);
            
        int sum = root->val;
        sum += dfs(root->left, low, high);
        sum += dfs(root->right, low, high);
        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
};