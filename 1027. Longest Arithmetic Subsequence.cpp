class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(1001, 1));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dif = nums[i] - nums[j] + 500;
                dp[j][dif] = max(dp[i][dif] + 1, dp[j][dif]);
                ans = max(ans, dp[j][dif]);
            }
        }

        return ans;
    }
};
