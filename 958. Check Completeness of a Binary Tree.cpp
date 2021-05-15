class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> qu;
        bool ans = true;
        qu.push(root);
        bool flag = true;
        while(!qu.empty())
        {
            int sz = qu.size();
            while(sz--){
               TreeNode *temp = qu.front();

               qu.pop();

               if(temp->left){
                   if(!flag) return false;
                   qu.push(temp->left);
               }
               else flag = false;

               if(temp->right){
                   if(!flag) return false;
                   qu.push(temp->right);
               }
               else flag = false;
            }
        }

        return ans;
    }
};
