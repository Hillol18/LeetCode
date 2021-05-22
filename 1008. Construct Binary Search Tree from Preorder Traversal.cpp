class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode *ans, *pre;

        if(preorder.size() == 0) return 0;

        int n = preorder.size();

        for(int i=0;i<n;i++){
            TreeNode* temp = new TreeNode(preorder[i]);

            if(st.empty() ) {
                st.push(temp);
                ans = temp;
            }
            else if(st.top()->val > temp->val){
                st.top()->left = temp;
                st.push(temp);
            }
            else{

                pre = NULL;
                while(!st.empty() && st.top()->val < temp->val){
                    pre = st.top();
                    st.pop();
                }

                pre->right = temp;
                st.push(temp);
            }
        }
        return ans;
    }
};
