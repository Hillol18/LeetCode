class Solution {
public:
    
    int dfs(int value, unordered_map<int, int> &dp, unordered_set<int> &st){
        //cout<<" "<<value<<endl;
        if(st.find(value) == st.end()) return 0;
        if(dp.find(value) != dp.end()) return dp[value];
        int &ret = dp[value];
         ret = 1 + dfs(value+1, dp, st);
     
        
        return ret;
    }
    
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        
        unordered_set<int> st;
        
        for(auto i: nums){
            st.insert(i);
        }
        
        int ans = 0;
        //cout<<dfs(3, mp, st)<<endl;
        for(auto i: nums){
            ans = max(ans, dfs(i, mp, st));
        }
        
        return ans;
    }
};