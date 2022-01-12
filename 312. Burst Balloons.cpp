class Solution {
public:
    int dfs(int i, int j, vector<int>&nums, vector<vector<int>> &dp){
        
        if(i+1 == j) return 0;
        int &ret = dp[i][j];
        if(ret != -1) return ret;
        ret = 0;
        for(int k = i+1; k<j; k++){
            ret = max(ret, nums[i]*nums[j]*nums[k] + dfs(i, k, nums, dp) + dfs(k, j, nums, dp));
        }
        return ret;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = dfs(0, n-1, nums, dp);
        return ans;
    }
};