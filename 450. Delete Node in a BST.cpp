class Solution {
public:
    
    
    TreeNode* dfs(TreeNode *root, int key){
        
        if(!root) return NULL;
        if(root->val == key){
            if(!root->left && !root->right)
                return NULL;
            
            if(!root->right) return root->left;
            
            if(!root->left) return root->right;
            
            TreeNode* n = root->right;
            
            while(n->left){
                n = n->left;    
            }
            
            root->val = n->val;
            
            root->right = dfs(root->right, root->val);
        }
        else if(root->val < key){
            root->right = dfs(root->right, key);
        }
        else {
            root->left = dfs(root->left, key);
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        return dfs(root, key);
    }
};