class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        int pre= 0, flag=0;
        while(root !=NULL || !st.empty()){

            while(root){
                st.push(root);
                root=root->left;
            }

            root = st.top();

            if(flag ==1 && pre >=root->val) return false;
            flag =1;
            pre = root->val;
            //cout<<st.size()<<" "<<root->val<<endl;
            st.pop();
            root= root->right;

        }
        return true;
    }
};
