class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
     queue<TreeNode*> qu;
     vector<double> ans;
        qu.push(root);

        while(!qu.empty()){
            int cnt = qu.size();
            long double total = 0.0;
            double frequency=cnt;
            while(cnt){
                TreeNode *temp = qu.front();
                qu.pop();
                if(temp->left){
                    qu.push(temp->left);
                }

                if(temp->right){
                    qu.push(temp->right);
                }

                total+=((double)temp->val);
                cnt--;
            }

            if(frequency){
                ans.push_back(total / frequency);
            }

        }

        return ans;
    }
};
