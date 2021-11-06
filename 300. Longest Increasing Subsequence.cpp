/*

           |
 0 1 0 3 2 3
 0 1 2 3 4 5       |
           
           
 0 2 3 9 9 9
 0 1 
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> data(n, INT_MAX);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int l = 0, r = n-1;
            int idx = 0;
            while(l <= r){
                int mid = (l+r)/2;
                
                if(data[mid] < nums[i]){
                    l = mid+1;
                }
                else{
                    idx = mid;
                    r = mid - 1;
                } 
            }
            data[idx] = nums[i];
            
            ans = max(ans, idx + 1);
        }
        return ans;
    }
};