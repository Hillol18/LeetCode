/*

[4,8,10,240]


4=-1
8=4
10
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> mp(nums.size());
        int cnt = 0, idx;
        vector<int> ans(nums.size());
        
        for(int i = 0; i<nums.size(); i++){
            int parent = -1;
            //cout<<nums[i]<<endl;
            for(int j = i - 1; j>= 0; j--){
                if(nums[i] % nums[j] == 0 && (parent == -1 || ans[parent] < ans[j])){
                    parent = j;
                }
            }
            
            
            mp[i] = parent;
            if(parent == -1) ans[i] = 1;
            else ans[i] = ans[parent] + 1;
            
            //cout<<parent<<endl;
            
            if(ans[i] > cnt){
                cnt = ans[i];
                idx = i;
            }
            //cout<<nums[i]<<endl;
        }
        //cout<<idx<<endl;
        vector<int> output;
        while(idx != -1){
            //cout<<idx<<endl;
            output.push_back(nums[idx]);
            idx = mp[idx];
        }
        return output;
    }
};