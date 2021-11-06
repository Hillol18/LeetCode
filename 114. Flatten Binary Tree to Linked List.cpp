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
    void flatten(TreeNode* root) {
        
        stack<TreeNode*> st;
        while(root){
            //cout<<root->val<<endl;
            if(root && root->left){
                if(root->right) st.push(root->right);
                root->right = root->left;
                root->left = NULL;
            }
                        
            if(!root -> right && !st.empty()){
                root ->right = st.top();
                st.pop();
            }
            
            root = root->right;
            
        }
    }
};