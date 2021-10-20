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

/*

1. camera set up in this position
2. Without setUp camera
3. cover by child

          1
         2  5
        3     6 (1 , 0, 0) 
(1)4
       


        1
     2 ()
   3(1,0,0)
   
   0 all node cover without this
   1 all node cover with this node without setup a camera here
   2 all node cover with this node also setup a camera here
   
*/

class Solution {
public:
    
    vector<int> dfs(TreeNode * root){
        if(!root) return {0, 0, 99999};
        
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        vector<int> ret(3);
        
        ret[0] = left[1] + right[1];
        int l12 = min(left[1], left[2]);
        int r12 = min(right[1], right[2]);
        
        ret[1] = min(right[2] + l12, left[2]+ r12);
        ret[2] = (min(l12, left[0]) +  min(right[0], r12) + 1);

        return ret;
    }
    
    int minCameraCover(TreeNode* root) {
        auto ret =  dfs(root);
        return min(ret[1], ret[2]);
    }
};