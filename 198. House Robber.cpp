/*

[1,2,3,1]

 1 2 4 3
   
 

*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int mx = 0;
        int pre = nums[0];
        int cur = nums[0]; 
        for(int i = 1; i<n; i++){
            pre = cur;
            cur = mx + nums[i];
            mx = max(mx, pre);
            
        }
        
        return max(pre, cur);
    }
};